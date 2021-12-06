#ifndef TIME_HELPER_H_8FVB3L0U
#define TIME_HELPER_H_8FVB3L0U

#ifndef DISABLE_TIMING
#include <ctime>
#include <cstdio>
// #include "log.hpp"
#include <string>

#ifdef _MSC_VER
#include <windows.h>
#include <WinSock.h>

static int gettimeofday(struct timeval *tp, void *tzp)
{
	time_t clock;
	struct tm tm;
	SYSTEMTIME wtm;
	GetLocalTime(&wtm);
	tm.tm_year = wtm.wYear - 1900;
	tm.tm_mon = wtm.wMonth - 1;
	tm.tm_mday = wtm.wDay;
	tm.tm_hour = wtm.wHour;
	tm.tm_min = wtm.wMinute;
	tm.tm_sec = wtm.wSecond;
	tm.tm_isdst = -1;
	clock = mktime(&tm);
	tp->tv_sec = clock;
	tp->tv_usec = wtm.wMilliseconds * 1000;
	return (0);
}

#else
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#endif

#define __TIC__(tag)                                           \
	struct timeval _##tag##_timing_start, _##tag##_timing_end; \
	gettimeofday(&_##tag##_timing_start, NULL);

#define __TOC__(tag)                                                                                                                                                                    \
	do                                                                                                                                                                                  \
	{                                                                                                                                                                                   \
		gettimeofday(&_##tag##_timing_end, NULL);                                                                                                                                       \
		double _##tag##_timing_gap = ((_##tag##_timing_end.tv_sec - _##tag##_timing_start.tv_sec) * 1000.0) + ((_##tag##_timing_end.tv_usec - _##tag##_timing_start.tv_usec) / 1000.0); \
		fprintf(stdout, "TIME(ms): %s %lf\n", #tag, _##tag##_timing_gap);                                                                                                               \
	} while (0)

#define __TOOC__(tag, time_result)                                                                                                                                                      \
	do                                                                                                                                                                                  \
	{                                                                                                                                                                                   \
		gettimeofday(&_##tag##_timing_end, NULL);                                                                                                                                       \
		double _##tag##_timing_gap = ((_##tag##_timing_end.tv_sec - _##tag##_timing_start.tv_sec) * 1000.0) + ((_##tag##_timing_end.tv_usec - _##tag##_timing_start.tv_usec) / 1000.0); \
		fprintf(stdout, "TIME(ms): %s %lf\n", #tag, _##tag##_timing_gap);                                                                                                               \
		time_result = _##tag##_timing_gap;                                                                                                                                              \
	} while (0)

#endif // DISABLE_TIMING
#endif // IMAGEHELPER_HPP_8FVB3L0U
