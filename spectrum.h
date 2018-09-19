#pragma once

#include "imgui.h"

/*
Color definitions in ImGui are a good starting point, 
but do not cover all the intricacies of Spectrum's possible colors
in controls and widgets. 

One big difference is that ImGui communicates widget activity 
(hover, pressed) with their background, while spectrum uses a mix
of background and border, with border being the most common choice.

Because of this, we reference spectrum colors from imgui.cpp
and imgui_widgets.cpp directly, and to make that work, we need
to define the theme here, in advance. 
*/

#define SPECTRUM_USE_LIGHT_THEME
//#define SPECTRUM_USE_DARK_THEME

namespace Spectrum {
    // a list of changes that I had to introduce to change the look
    // of the widgets. Collected here as constexpr rather than being
    // magic numbers spread around imgui.cpp and imgui_widgets.cpp.
    constexpr float CHECKBOX_BORDER_SIZE = 2.0f;

    namespace {
        constexpr unsigned int Color(unsigned int c) {
            // add alpha.
            // also swap red and blue channel for some reason.
            // todo: figure out why, and fix it.
            const short a = 0xFF;
            const short r = (c >> 16) & 0xFF;
            const short g = (c >> 8) & 0xFF;
            const short b = (c >> 0) & 0xFF;
            return(a << 24)
                | (r << 0)
                | (g << 8)
                | (b << 16);
        }
    }
    // all colors are from http://spectrum.corp.adobe.com/color.html

    namespace Static { // static colors
        constexpr unsigned int NONE = 0x00000000; // transparent
        constexpr unsigned int WHITE = Color(0xFFFFFF);
        constexpr unsigned int BLACK = Color(0x000000);
        constexpr unsigned int GREY200 = Color(0xF4F4F4);
        constexpr unsigned int GREY300 = Color(0xEAEAEA);
        constexpr unsigned int GREY400 = Color(0xD3D3D3);
        constexpr unsigned int GREY500 = Color(0xBCBCBC);
        constexpr unsigned int GREY600 = Color(0x959595);
        constexpr unsigned int GREY700 = Color(0x767676);
        constexpr unsigned int GREY800 = Color(0x505050);
        constexpr unsigned int GREY900 = Color(0x323232);
        constexpr unsigned int BLUE400 = Color(0x378EF0);
        constexpr unsigned int BLUE500 = Color(0x2680EB);
        constexpr unsigned int BLUE600 = Color(0x1473E6);
        constexpr unsigned int BLUE700 = Color(0x0D66D0);
        constexpr unsigned int RED400 = Color(0xEC5B62);
        constexpr unsigned int RED500 = Color(0xE34850);
        constexpr unsigned int RED600 = Color(0xD7373F);
        constexpr unsigned int RED700 = Color(0xC9252D);
        constexpr unsigned int ORANGE400 = Color(0xF29423);
        constexpr unsigned int ORANGE500 = Color(0xE68619);
        constexpr unsigned int ORANGE600 = Color(0xDA7B11);
        constexpr unsigned int ORANGE700 = Color(0xCB6F10);
        constexpr unsigned int GREEN400 = Color(0x33AB84);
        constexpr unsigned int GREEN500 = Color(0x2D9D78);
        constexpr unsigned int GREEN600 = Color(0x268E6C);
        constexpr unsigned int GREEN700 = Color(0x12805C);
    }

#ifdef SPECTRUM_USE_LIGHT_THEME
    constexpr unsigned int GRAY50 = Color(0xFFFFFF);
    constexpr unsigned int GRAY75 = Color(0xFAFAFA);
    constexpr unsigned int GRAY100 = Color(0xF5F5F5);
    constexpr unsigned int GRAY200 = Color(0xEAEAEA);
    constexpr unsigned int GRAY300 = Color(0xE1E1E1);
    constexpr unsigned int GRAY400 = Color(0xCACACA);
    constexpr unsigned int GRAY500 = Color(0xB3B3B3);
    constexpr unsigned int GRAY600 = Color(0x8E8E8E);
    constexpr unsigned int GRAY700 = Color(0x707070);
    constexpr unsigned int GRAY800 = Color(0x4B4B4B);
    constexpr unsigned int GRAY900 = Color(0x2C2C2C);
    constexpr unsigned int BLUE400 = Color(0x2680EB);
    constexpr unsigned int BLUE500 = Color(0x1473E6);
    constexpr unsigned int BLUE600 = Color(0x0D66D0);
    constexpr unsigned int BLUE700 = Color(0x095ABA);
    constexpr unsigned int RED400 = Color(0xE34850);
    constexpr unsigned int RED500 = Color(0xD7373F);
    constexpr unsigned int RED600 = Color(0xC9252D);
    constexpr unsigned int RED700 = Color(0xBB121A);
    constexpr unsigned int ORANGE400 = Color(0xE68619);
    constexpr unsigned int ORANGE500 = Color(0xDA7B11);
    constexpr unsigned int ORANGE600 = Color(0xCB6F10);
    constexpr unsigned int ORANGE700 = Color(0xBD640D);
    constexpr unsigned int GREEN400 = Color(0x2D9D78);
    constexpr unsigned int GREEN500 = Color(0x268E6C);
    constexpr unsigned int GREEN600 = Color(0x12805C);
    constexpr unsigned int GREEN700 = Color(0x107154);
    constexpr unsigned int INDIGO400 = Color(0x6767EC);
    constexpr unsigned int INDIGO500 = Color(0x5C5CE0);
    constexpr unsigned int INDIGO600 = Color(0x5151D3);
    constexpr unsigned int INDIGO700 = Color(0x4646C6);
    constexpr unsigned int CELERY400 = Color(0x44B556);
    constexpr unsigned int CELERY500 = Color(0x3DA74E);
    constexpr unsigned int CELERY600 = Color(0x379947);
    constexpr unsigned int CELERY700 = Color(0x318B40);
    constexpr unsigned int MAGENTA400 = Color(0xD83790);
    constexpr unsigned int MAGENTA500 = Color(0xCE2783);
    constexpr unsigned int MAGENTA600 = Color(0xBC1C74);
    constexpr unsigned int MAGENTA700 = Color(0xAE0E66);
    constexpr unsigned int YELLOW400 = Color(0xDFBF00);
    constexpr unsigned int YELLOW500 = Color(0xD2B200);
    constexpr unsigned int YELLOW600 = Color(0xC4A600);
    constexpr unsigned int YELLOW700 = Color(0xB79900);
    constexpr unsigned int FUCHSIA400 = Color(0xC038CC);
    constexpr unsigned int FUCHSIA500 = Color(0xB130BD);
    constexpr unsigned int FUCHSIA600 = Color(0xA228AD);
    constexpr unsigned int FUCHSIA700 = Color(0x93219E);
    constexpr unsigned int SEAFOAM400 = Color(0x1B959A);
    constexpr unsigned int SEAFOAM500 = Color(0x16878C);
    constexpr unsigned int SEAFOAM600 = Color(0x0F797D);
    constexpr unsigned int SEAFOAM700 = Color(0x096C6F);
    constexpr unsigned int CHARTREUSE400 = Color(0x85D044);
    constexpr unsigned int CHARTREUSE500 = Color(0x7CC33F);
    constexpr unsigned int CHARTREUSE600 = Color(0x73B53A);
    constexpr unsigned int CHARTREUSE700 = Color(0x6AA834);
    constexpr unsigned int PURPLE400 = Color(0x9256D9);
    constexpr unsigned int PURPLE500 = Color(0x864CCC);
    constexpr unsigned int PURPLE600 = Color(0x7A42BF);
    constexpr unsigned int PURPLE700 = Color(0x6F38B1);
#endif
#ifdef SPECTRUM_USE_DARK_THEME
    constexpr unsigned int GRAY50 = Color(0x252525);
    constexpr unsigned int GRAY75 = Color(0x2F2F2F);
    constexpr unsigned int GRAY100 = Color(0x323232);
    constexpr unsigned int GRAY200 = Color(0x393939);
    constexpr unsigned int GRAY300 = Color(0x3E3E3E);
    constexpr unsigned int GRAY400 = Color(0x4D4D4D);
    constexpr unsigned int GRAY500 = Color(0x5C5C5C);
    constexpr unsigned int GRAY600 = Color(0x7B7B7B);
    constexpr unsigned int GRAY700 = Color(0x999999);
    constexpr unsigned int GRAY800 = Color(0xCDCDCD);
    constexpr unsigned int GRAY900 = Color(0xFFFFFF);
    constexpr unsigned int BLUE400 = Color(0x2680EB);
    constexpr unsigned int BLUE500 = Color(0x378EF0);
    constexpr unsigned int BLUE600 = Color(0x4B9CF5);
    constexpr unsigned int BLUE700 = Color(0x5AA9FA);
    constexpr unsigned int RED400 = Color(0xE34850);
    constexpr unsigned int RED500 = Color(0xEC5B62);
    constexpr unsigned int RED600 = Color(0xF76D74);
    constexpr unsigned int RED700 = Color(0xFF7B82);
    constexpr unsigned int ORANGE400 = Color(0xE68619);
    constexpr unsigned int ORANGE500 = Color(0xF29423);
    constexpr unsigned int ORANGE600 = Color(0xF9A43F);
    constexpr unsigned int ORANGE700 = Color(0xFFB55B);
    constexpr unsigned int GREEN400 = Color(0x2D9D78);
    constexpr unsigned int GREEN500 = Color(0x33AB84);
    constexpr unsigned int GREEN600 = Color(0x39B990);
    constexpr unsigned int GREEN700 = Color(0x3FC89C);
    constexpr unsigned int INDIGO400 = Color(0x6767EC);
    constexpr unsigned int INDIGO500 = Color(0x7575F1);
    constexpr unsigned int INDIGO600 = Color(0x8282F6);
    constexpr unsigned int INDIGO700 = Color(0x9090FA);
    constexpr unsigned int CELERY400 = Color(0x44B556);
    constexpr unsigned int CELERY500 = Color(0x4BC35F);
    constexpr unsigned int CELERY600 = Color(0x51D267);
    constexpr unsigned int CELERY700 = Color(0x58E06F);
    constexpr unsigned int MAGENTA400 = Color(0xD83790);
    constexpr unsigned int MAGENTA500 = Color(0xE2499D);
    constexpr unsigned int MAGENTA600 = Color(0xEC5AAA);
    constexpr unsigned int MAGENTA700 = Color(0xF56BB7);
    constexpr unsigned int YELLOW400 = Color(0xDFBF00);
    constexpr unsigned int YELLOW500 = Color(0xEDCC00);
    constexpr unsigned int YELLOW600 = Color(0xFAD900);
    constexpr unsigned int YELLOW700 = Color(0xFFE22E);
    constexpr unsigned int FUCHSIA400 = Color(0xC038CC);
    constexpr unsigned int FUCHSIA500 = Color(0xCF3EDC);
    constexpr unsigned int FUCHSIA600 = Color(0xD951E5);
    constexpr unsigned int FUCHSIA700 = Color(0xE366EF);
    constexpr unsigned int SEAFOAM400 = Color(0x1B959A);
    constexpr unsigned int SEAFOAM500 = Color(0x20A3A8);
    constexpr unsigned int SEAFOAM600 = Color(0x23B2B8);
    constexpr unsigned int SEAFOAM700 = Color(0x26C0C7);
    constexpr unsigned int CHARTREUSE400 = Color(0x85D044);
    constexpr unsigned int CHARTREUSE500 = Color(0x8EDE49);
    constexpr unsigned int CHARTREUSE600 = Color(0x9BEC54);
    constexpr unsigned int CHARTREUSE700 = Color(0xA3F858);
    constexpr unsigned int PURPLE400 = Color(0x9256D9);
    constexpr unsigned int PURPLE500 = Color(0x9D64E1);
    constexpr unsigned int PURPLE600 = Color(0xA873E9);
    constexpr unsigned int PURPLE700 = Color(0xB483F0);
#endif
}