#pragma once
#include <Windows.h>
#include "Log.h"
#include <stdarg.h>

#define LOG(format, ...) LogPrint(__FILE__, __LINE__, format, __VA_ARGS__)

enum update_status
{
	UPDATE_CONTINUE = 1,
	UPDATE_STOP,
	UPDATE_ERROR
};
