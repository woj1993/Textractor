#include "textthread.h"
#include "const.h"
#include "host.h"
#include "util.h"

TextThread::TextThread(ThreadParam tp, HookParam hp, std::wstring name) : 
	handle(threadCounter++),
	name(name),
	tp(tp), 
	hp(hp),
	deletionEvent(CreateEventW(nullptr, FALSE, FALSE, NULL)),
	flushThread([&] { Host::Setup(); while (WaitForSingleObject(deletionEvent, 10) == WAIT_TIMEOUT) Flush(); })
{}

TextThread::~TextThread()
{
	SetEvent(deletionEvent);
	flushThread.join();
	CloseHandle(deletionEvent);
}

std::wstring TextThread::GetStorage()
{
	LOCK(storageMutex);
	return storage;
}

void TextThread::AddSentence(std::wstring sentence)
{
	if (Output(this, sentence))
	{
		LOCK(storageMutex);
		storage += sentence;
	}
}

void TextThread::Push(const BYTE* data, int len)
{
	if (len < 0) return;
	LOCK(bufferMutex);
	buffer += hp.type & USING_UNICODE
		? std::wstring((wchar_t*)data, len / 2)
		: Util::StringToWideString(std::string((char*)data, len), hp.codepage ? hp.codepage : defaultCodepage);
	if (std::all_of(buffer.begin(), buffer.end(), [&](wchar_t c) { return repeatingChars.count(c) > 0; })) buffer.clear();
	lastPushTime = GetTickCount();
}

void TextThread::Flush()
{
	std::wstring sentence;
	{
		LOCK(bufferMutex);
		if (buffer.empty()) return;
		if (buffer.size() < maxBufferSize && GetTickCount() - lastPushTime < flushDelay) return;
		sentence = buffer;
		buffer.clear();

		if (Util::RemoveRepetition(sentence)) repeatingChars = std::unordered_set(sentence.begin(), sentence.end());
		else repeatingChars.clear();
	}
	AddSentence(sentence);
}
