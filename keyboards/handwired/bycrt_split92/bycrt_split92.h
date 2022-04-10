#pragma once

#include "quantum.h"

#define LAYOUT_92( \
    L000,  L001,  L002,  L003,  L004,  L005,  L006,  L007,        R008,  R009,  R010,  R011,  R012,         R014,  R015,  R016, \
    L100,  L101,  L102,  L103,  L104,  L105,  L106,  L107,        R108,  R109,  R110,  R111,  R112,  R113,         R115,  R116, \
    L200,  L201,         L203,  L204,  L205,  L206,  L207,        R208,  R209,  R210,  R211,  R212,  R213,  R214,  R215,  R216, \
    L300,  L301,         L303,  L304,  L305,  L306,  L307,        R308,  R309,  R310,  R311,  R312,  R313,         R315,  R316, \
    L400,         L402,  L403,  L404,  L405,  L406,  L407,        R408,  R409,  R410,  R411,  R412,         R414,  R415,  R416, \
    L500,  L501,  L502,  L503,  L504,         L506,               R508,         R510,  R511,  R512,  R513,  R514,  R515,  R516  \
) { \
  { L000,  L001,  L002,  L003,  L004,  L005,  L006,  L007 }, \
  { L100,  L101,  L102,  L103,  L104,  L105,  L106,  L107 }, \
  { L200,  L201,  KC_NO, L203,  L204,  L205,  L206,  L207 }, \
  { L300,  L301,  KC_NO, L303,  L304,  L305,  L306,  L307 }, \
  { L400,  KC_NO, L402,  L403,  L404,  L405,  L406,  L407 }, \
  { L500,  L501,  L502,  L503,  L504,  KC_NO, L506,  KC_NO } \
  { R008,  R009,  R010,  R011,  R012,  KC_NO, R014,  R015,  R016 }, \
  { R108,  R109,  R110,  R111,  R112,  R113,  KC_NO, R115,  R116 }, \
  { R208,  R209,  R210,  R211,  R212,  R213,  R214,  R215,  R216 }, \
  { R308,  R309,  R310,  R311,  R312,  R313,  KC_NO, R315,  R316 }, \
  { R408,  R409,  R410,  R411,  R412,  KC_NO, R414,  R415,  R416 }, \
  { R508,  KC_NO, R510,  R511,  R512,  R513,  R514,  R515,  R516 } \
}
