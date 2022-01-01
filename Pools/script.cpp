#include "script.h"
#include "keyboard.h"

#include <unordered_map>
#include <vector>
#include <string>
#include <ctime>

void drawstring(std::string string, float X, float Y)
{
	std::string Template = "<FONT FACE='$Font5_limited' COLOR='#%04X'>" + string + "</FONT>";
	const char* InsertTemplate = MISC::VAR_STRING(10, "LITERAL_STRING", _strdup(Template.c_str()));
    UIDEBUG::_BG_SET_TEXT_SCALE(0.5f, 0.5f);
    UIDEBUG::_BG_SET_TEXT_COLOR(0, 0, 0, 255);
    UIDEBUG::_BG_DISPLAY_TEXT(MISC::VAR_STRING(42, "COLOR_STRING", 0, InsertTemplate), X + 0.0009f, Y);
    UIDEBUG::_BG_SET_TEXT_SCALE(0.5f, 0.5f);
    UIDEBUG::_BG_SET_TEXT_COLOR(0, 0, 0, 255);
    UIDEBUG::_BG_DISPLAY_TEXT(MISC::VAR_STRING(42, "COLOR_STRING", 0, InsertTemplate), X - 0.0009f, Y);
    UIDEBUG::_BG_SET_TEXT_SCALE(0.5f, 0.5f);
    UIDEBUG::_BG_SET_TEXT_COLOR(0, 0, 0, 255);
    UIDEBUG::_BG_DISPLAY_TEXT(MISC::VAR_STRING(42, "COLOR_STRING", 0, InsertTemplate), X, Y + 0.0009f);
    UIDEBUG::_BG_SET_TEXT_SCALE(0.5f, 0.5f);
    UIDEBUG::_BG_SET_TEXT_COLOR(0, 0, 0, 255);
    UIDEBUG::_BG_DISPLAY_TEXT(MISC::VAR_STRING(42, "COLOR_STRING", 0, InsertTemplate), X, Y - 0.0009f);
    UIDEBUG::_BG_SET_TEXT_SCALE(0.5f, 0.5f);
	UIDEBUG::_BG_DISPLAY_TEXT(MISC::VAR_STRING(42, "COLOR_STRING", 0, InsertTemplate), X, Y);
}

void ScriptMain()
{
	while (true)
	{
        std::string h = "";
        std::string m = "";
        bool after12 = true;
        if (CLOCK::GET_CLOCK_HOURS() < 10)
        {
            h += "0";
            h += std::to_string(CLOCK::GET_CLOCK_HOURS());
        }
        else
        {
            if (CLOCK::GET_CLOCK_HOURS() > 12)
            {
                h += std::to_string(CLOCK::GET_CLOCK_HOURS() - 12);
            }
            else
            {
                h += std::to_string(CLOCK::GET_CLOCK_HOURS());
            }
        }
        if (CLOCK::GET_CLOCK_MINUTES() < 10)
        {
            m += "0";
            m += std::to_string(CLOCK::GET_CLOCK_MINUTES());
        }
        else
        {
            m += std::to_string(CLOCK::GET_CLOCK_MINUTES());
        }
        if (after12)
        {
            m += " P.M.";
        }
        std::string CLOCK = h + ":" + m;
        char* CLOCK1 = new char[CLOCK.length() + 1];
        strcpy(CLOCK1, CLOCK.c_str());
        //DrawText(0.5f, 0.5f, CLOCK1);
        drawstring(CLOCK, 0.01f, 0.01f);
		WAIT(0);
	}
}
