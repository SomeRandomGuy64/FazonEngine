#pragma once

#include "fzpch.h"
#include <stdint.h>

#include <imgui/imgui.h>
#include <SDL3/SDL.h>

namespace Fazon {

	using KeyCode = uint16_t;

    char convertFazonKeyToChar(KeyCode key);
    ImGuiKey convertFazonKeyToImguiKeyCode(KeyCode keycode);
    KeyCode convertSDLKeyToFazonKey(SDL_KeyboardEvent sdlKey);
    SDL_Keycode converFazonKeyToSDLKey(KeyCode keycode);

	namespace Key {

        // Keys which are supposed to be visible AS A CHRACTER when typed are grouped together: KeyCodes 4 - 128
        // Keys which are not supposed to be visible when typed are grouped together: KeyCodes KeyCodes 256 - 399
		enum : KeyCode {

            // Taken from SDL3/SDL_scancode.h

            Unknown = 0,

            /**
             *  \name Usage page 0x07
             *
             *  These values are from usage page 0x07 (USB keyboard page).
             */
             /* @{ */

            A = 4,
            B = 5,
            C = 6,
            D = 7,
            E = 8,
            F = 9,
            G = 10,
            H = 11,
            I = 12,
            J = 13,
            K = 14,
            L = 15,
            M = 16,
            N = 17,
            O = 18,
            P = 19,
            Q = 20,
            R = 21,
            S = 22,
            T = 23,
            U = 24,
            V = 25,
            W = 26,
            X = 27,
            Y = 28,
            Z = 29,

            One = 30,
            Two = 31,
            Three = 32,
            Four = 33,
            Five = 34,
            Six = 35,
            Seven = 36,
            Eight = 37,
            Nine = 38,
            Zero = 39,

            Return = 256,
            Escape = 257,
            Backspace = 258,
            Tab = 259,
            Space = 40,

            Minus = 41,
            Equals = 42,
            LeftBracket = 43,
            RightBracket = 44,
            Backslash = 45,                 /**< Located at the lower left of the return
                                          *   key on ISO keyboards and at the right end
                                          *   of the QWERTY row on ANSI keyboards.
                                          *   Produces REVERSE SOLIDUS (backslash) and
                                          *   VERTICAL LINE in a US layout, REVERSE
                                          *   SOLIDUS and VERTICAL LINE in a UK Mac
                                          *   layout, NUMBER SIGN and TILDE in a UK
                                          *   Windows layout, DOLLAR SIGN and POUND SIGN
                                          *   in a Swiss German layout, NUMBER SIGN and
                                          *   APOSTROPHE in a German layout, GRAVE
                                          *   ACCENT and POUND SIGN in a French Mac
                                          *   layout, and ASTERISK and MICRO SIGN in a
                                          *   French Windows layout.
                                          */
            NonUSHash = 46,                /**< ISO USB keyboards actually use this code
                                          *   instead of 49 for the same key, but all
                                          *   OSes I've seen treat the two codes
                                          *   identically. So, as an implementor, unless
                                          *   your keyboard generates both of those
                                          *   codes and your OS treats them differently,
                                          *   you should generate SDL_SCANCODE_BACKSLASH
                                          *   instead of this code. As a user, you
                                          *   should not rely on this code because SDL
                                          *   will never generate it with most (all?)
                                          *   keyboards.
                                          */
            Semicolon = 47,
            Apostrophe = 48,
            Grave = 49,                 /**< Located in the top left corner (on both ANSI
                                      *   and ISO keyboards). Produces GRAVE ACCENT and
                                      *   TILDE in a US Windows layout and in US and UK
                                      *   Mac layouts on ANSI keyboards, GRAVE ACCENT
                                      *   and NOT SIGN in a UK Windows layout, SECTION
                                      *   SIGN and PLUS-MINUS SIGN in US and UK Mac
                                      *   layouts on ISO keyboards, SECTION SIGN and
                                      *   DEGREE SIGN in a Swiss German layout (Mac:
                                      *   only on ISO keyboards), CIRCUMFLEX ACCENT and
                                      *   DEGREE SIGN in a German layout (Mac: only on
                                      *   ISO keyboards), SUPERSCRIPT TWO and TILDE in a
                                      *   French Windows layout, COMMERCIAL AT and
                                      *   NUMBER SIGN in a French Mac layout on ISO
                                      *   keyboards, and LESS-THAN SIGN and GREATER-THAN
                                      *   SIGN in a Swiss German, German, or French Mac
                                      *   layout on ANSI keyboards.
                                      */
            Comma = 50,
            Period = 51,
            Slash = 52,

            CapsLock = 261,

            F1 = 262,
            F2 = 263,
            F3 = 264,
            F4 = 265,
            F5 = 266,
            F6 = 267,
            F7 = 268,
            F8 = 269,
            F9 = 270,
            F10 = 271,
            F11 = 272,
            F12 = 273,

            PrintScreen = 274,
            ScrollLock = 275,
            Pause = 276,
            Insert = 277,                /**< insert on PC, help on some Mac keyboards (but
                                           does send code 73, not 117) */
            Home = 278,
            PageUp = 279,
            Delete = 280,
            End = 281,
            PageDown = 282,
            Right = 283,
            Left = 284,
            Down = 285,
            Up = 286,

            NumLock = 287, // num lock on PC, clear on Mac keyboards

            // Keypad
            KpDivide = 53,
            KpMultiply = 54,
            KpMinus = 55,
            KpPlus = 56,
            KpEnter = 57,
            KpOne = 58,
            KpTwo = 59,
            KpThree = 60,
            KpFour = 61,
            KpFive = 62,
            KpSix = 63,
            KpSeven = 64,
            KpEight = 65,
            KpNine = 66,
            KpZero = 67,
            KpPeriod = 68,
            KpFullStop = 69,

            NonUSBackslash = 70, /**< This is the additional key that ISO
                                                *   keyboards have over ANSI ones,
                                                *   located between left shift and Y.
                                                *   Produces GRAVE ACCENT and TILDE in a
                                                *   US or UK Mac layout, REVERSE SOLIDUS
                                                *   (backslash) and VERTICAL LINE in a
                                                *   US or UK Windows layout, and
                                                *   LESS-THAN SIGN and GREATER-THAN SIGN
                                                *   in a Swiss German, German, or French
                                                *   layout. */
            Application = 288, /**< windows contextual menu, compose */
            Power = 289, /**< The USB document says this is a status flag,
                                       *   not a physical key - but some Mac keyboards
                                       *   do have a power key. */
            KpEquals = 71,
            F13 = 290,
            F14 = 291,
            F15 = 292,
            F16 = 293,
            F17 = 294,
            F18 = 295,
            F19 = 296,
            F20 = 297,
            F21 = 298,
            F22 = 299,
            F23 = 300,
            F24 = 301,
            Execute = 302,
            Help = 303,    /**< AL Integrated Help Center */
            Menu = 304,    /**< Menu (show menu) */
            Select = 305,
            AcStop = 306,    /**< AC Stop */
            AcAgain = 307,   /**< AC Redo/Repeat */
            AcUndo = 308,    /**< AC Undo */
            AcCut = 309,     /**< AC Cut */
            AcCopy = 310,    /**< AC Copy */
            AcPaste = 311,   /**< AC Paste */
            AcFind = 312,    /**< AC Find */
            Mute = 313,
            VolumeUp = 314,
            VolumeDown = 315,

            KpComma = 72,
            KpEqualsAs400 = 73,

            International1 = 74, /**< used on Asian keyboards, see
                                                    footnotes in USB doc */
            International12 = 75,
            International3 = 76, /**< Yen */
            International4 = 77,
            International5 = 78,
            International6 = 79,
            International7 = 80,
            International8 = 81,
            International9 = 82,
            Lang1 = 316, /**< Hangul/English toggle */
            Lang2 = 317, /**< Hanja conversion */
            Lang3 = 318, /**< Katakana */
            Lang4 = 319, /**< Hiragana */
            Lang5 = 320, /**< Zenkaku/Hankaku */
            Lang6 = 321, /**< reserved */
            Lang7 = 322, /**< reserved */
            Lang8 = 323, /**< reserved */
            Lang9 = 324, /**< reserved */

            AltErase = 325,    /**< Erase-Eaze */
            SysReq = 326,
            AcCancel = 327,      /**< AC Cancel */
            Clear = 328,
            Prior = 329,
            Return2 = 330,
            Seperator = 331,
            Out = 332,
            Oper = 333,
            ClearAgain = 334,
            CRSEL = 335,
            EXSEL = 336,

            Kp00 = 83,
            Kp000 = 84,
            ThousandsSeperator = 85,
            DecimalSeperator = 86,
            CurrencyUnit = 87,
            CurrencySubUnit = 88,
            KpLeftParenthesis = 89,
            KpRightParenthesis = 90,
            KpLeftBrace = 91,
            KpRightBrace = 92,
            KpTab = 337,
            KpBackspace = 338,
            KpA = 93,
            KpB = 94,
            KpC = 95,
            KpD = 96,
            KpE = 97,
            KpF = 98,
            KpXOR = 339,
            KpPower = 340,
            KpPercent = 99,
            KpLess = 100,
            KpGreater = 101,
            KpAmpersand = 102,
            KpDoubleAmpersand = 103,
            KpVerticalBar = 104,
            KpDoubleVerticalBar = 105,
            KpColon = 106,
            KpHash = 107,
            KpSpace = 108,
            KpAt = 109,
            KpExclam = 110,
            KpMemstore = 341,
            KpMemRecall = 342,
            KpMemClear = 343,
            KpMemAdd = 111,
            KpMemSubtract = 112,
            KpMemMultiply = 113,
            KpMemDivide = 114,
            KpPlusMinus = 115,
            KpClear = 344,
            KpClearEntry = 345,
            KpBinary = 346,
            KpOctal = 347,
            KpDecimal = 348,
            KpHexadecimal = 349,

            KpLeftCtrl = 350,
            KpLeftShift = 351,
            KpLeftAlt = 352, /**< alt, option */
            KpLeftGUI = 353, /**< windows, command (apple), meta */
            KpRightCtrl = 354,
            KpRightShift = 355,
            KpRightAlt = 356, /**< alt gr, option */
            KpRightGUI = 357, /**< windows, command (apple), meta */

            KpScanMode = 358,    /**< I'm not sure if this is really not covered
                                         *   by any of the above, but since there's a
                                         *   special SDL_KMOD_MODE for it I'm adding it here
                                         */

                                         /* @} *//* Usage page 0x07 */

                                         /**
                                          *  \name Usage page 0x0C
                                          *
                                          *  These values are mapped from usage page 0x0C (USB consumer page).
                                          *
                                          *  There are way more keys in the spec than we can represent in the
                                          *  current scancode range, so pick the ones that commonly come up in
                                          *  real world usage.
                                          */
                                          /* @{ */

            KpSleep = 359,                   /**< Sleep */
            KpWake = 360,                    /**< Wake */

            Increment = 361,       /**< Channel Increment */
            Decrement = 362,       /**< Channel Decrement */

            MediaPlay = 363,          /**< Play */
            MediaPause = 364,         /**< Pause */
            MediaRecord = 365,        /**< Record */
            MediaFastForward = 366,  /**< Fast Forward */
            MediaRewind = 367,        /**< Rewind */
            MediaNextTrack = 368,    /**< Next Track */
            MediaPreviousTrack = 369, /**< Previous Track */
            MediaStop = 370,          /**< Stop */
            MediaEject = 371,         /**< Eject */
            MediaPlayPause = 372,    /**< Play / Pause */
            MediaSelect = 373,        /* Media Select */

            AcNew = 374,              /**< AC New */
            AcOpen = 375,             /**< AC Open */
            AcClose = 376,            /**< AC Close */
            AcExit = 377,             /**< AC Exit */
            AcSave = 378,             /**< AC Save */
            AcPrint = 379,            /**< AC Print */
            AcProperties = 380,       /**< AC Properties */

            AcSearch = 381,           /**< AC Search */
            AcHome = 382,             /**< AC Home */
            AcBack = 383,             /**< AC Back */
            AcForward = 384,          /**< AC Forward */
            AcStop2 = 385,             /**< AC Stop */
            AcRefresh = 386,          /**< AC Refresh */
            AcBookmarks = 387,        /**< AC Bookmarks */

            /* @} *//* Usage page 0x0C */


            /**
             *  \name Mobile keys
             *
             *  These are values that are often used on mobile phones.
             */
             /* @{ */

            SoftLeft = 388, /**< Usually situated below the display on phones and
                                              used as a multi-function feature key for selecting
                                              a software defined function shown on the bottom left
                                              of the display. */
            SoftRight = 389, /**< Usually situated below the display on phones and
                                               used as a multi-function feature key for selecting
                                               a software defined function shown on the bottom right
                                               of the display. */
            Call = 390, /**< Used for accepting phone calls. */
            EndCall = 391, /**< Used for rejecting phone calls. */

            /* @} *//* Mobile keys */

            /* Add any other keys here. */

            Reserved = 400,    /**< 400-500 reserved for dynamic keycodes */

            Count = 512 /**< not a key, just marks the number of scancodes for array bounds */

		};

	}

}