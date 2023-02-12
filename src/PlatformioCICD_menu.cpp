/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
 */

#include <tcMenu.h>
#include "PlatformioCICD_menu.h"
#include "ThemeMonoInverse.h"

// Global variable declarations
const  ConnectorLocalInfo applicationInfo = { "Polyformer", "ecd5607f-55eb-4252-a512-aab769452dd3" };
IoAbstractionRef ioexp_myIoOverI2c = ioFrom8574(0x38, -1);
I2cAt24Eeprom glI2cRom(0x50, PAGESIZE_AT24C01);
EepromAuthenticatorManager authManager(4);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C gfx(U8G2_R0, U8X8_PIN_NONE, U8X8_PIN_NONE, U8X8_PIN_NONE);
U8g2Drawable gfxDrawable(&gfx, &Wire);
GraphicsDeviceRenderer renderer(30, applicationInfo.name, &gfxDrawable);

// Global Menu Item declarations
const char enumStrDecimalStep_0[] = "1x";
const char enumStrDecimalStep_1[] = "2x";
const char enumStrDecimalStep_2[] = "4x";
const char* const enumStrDecimalStep[]  = { enumStrDecimalStep_0, enumStrDecimalStep_1, enumStrDecimalStep_2 };
const EnumMenuInfo minfoDecimalStep = { "Decimal Step", 16, 23, 2, onDecimalStepChange, enumStrDecimalStep };
EnumMenuItem menuDecimalStep(&minfoDecimalStep, 0, NULL);
const char pgmStrRuntimesAuthenticatorText[] = { "Authenticator" };
EepromAuthenticationInfoMenuItem menuRuntimesAuthenticator(pgmStrRuntimesAuthenticatorText, NO_CALLBACK, 15, NULL);
const char pgmStrRuntimesIoTMonitorText[] = { "IoT Monitor" };
RemoteMenuItem menuRuntimesIoTMonitor(pgmStrRuntimesIoTMonitorText, 14, &menuRuntimesAuthenticator);
ListRuntimeMenuItem menuRuntimesCustomList(13, 0, fnRuntimesCustomListRtCall, &menuRuntimesIoTMonitor);
RENDERING_CALLBACK_NAME_INVOKE(fnRuntimesTextRtCall, textItemRenderFn, "Text", 18, NO_CALLBACK)
TextMenuItem menuRuntimesText(fnRuntimesTextRtCall, "", 12, 5, &menuRuntimesCustomList);
RENDERING_CALLBACK_NAME_INVOKE(fnRuntimesRtCall, backSubItemRenderFn, "Runtimes", -1, NO_CALLBACK)
const SubMenuInfo minfoRuntimes = { "Runtimes", 11, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackRuntimes(fnRuntimesRtCall, &menuRuntimesText);
SubMenuItem menuRuntimes(&minfoRuntimes, &menuBackRuntimes, &menuDecimalStep);
extern char ramDataSet[];
RENDERING_CALLBACK_NAME_INVOKE(fnMoreItemsScrollRtCall, enumItemRenderFn, "Scroll", -1, NO_CALLBACK)
ScrollChoiceMenuItem menuMoreItemsScroll(10, fnMoreItemsScrollRtCall, 0, ramDataSet, 10, 5, NULL);
const FloatMenuInfo minfoMoreItemsNumber = { "Number", 9, 0xffff, 2, NO_CALLBACK };
FloatMenuItem menuMoreItemsNumber(&minfoMoreItemsNumber, 0.0, &menuMoreItemsScroll);
const AnyMenuInfo minfoMoreItemsPressMe = { "Save", 8, 0xffff, 0, saveWasPressed };
ActionMenuItem menuMoreItemsPressMe(&minfoMoreItemsPressMe, &menuMoreItemsNumber);
const BooleanMenuInfo minfoMoreItemsPower = { "Power", 7, 17, 1, NO_CALLBACK, NAMING_ON_OFF };
BooleanMenuItem menuMoreItemsPower(&minfoMoreItemsPower, false, &menuMoreItemsPressMe);
const BooleanMenuInfo minfoMoreItemsToppings = { "Toppings", 6, 16, 1, NO_CALLBACK, NAMING_YES_NO };
BooleanMenuItem menuMoreItemsToppings(&minfoMoreItemsToppings, false, &menuMoreItemsPower);
const char enumStrMoreItemsOptions_0[] = "Pizza";
const char enumStrMoreItemsOptions_1[] = "Pasta";
const char enumStrMoreItemsOptions_2[] = "Salad";
const char* const enumStrMoreItemsOptions[]  = { enumStrMoreItemsOptions_0, enumStrMoreItemsOptions_1, enumStrMoreItemsOptions_2 };
const EnumMenuInfo minfoMoreItemsOptions = { "Options", 5, 14, 2, NO_CALLBACK, enumStrMoreItemsOptions };
EnumMenuItem menuMoreItemsOptions(&minfoMoreItemsOptions, 0, &menuMoreItemsToppings);
RENDERING_CALLBACK_NAME_INVOKE(fnMoreItemsRtCall, backSubItemRenderFn, "More Items", -1, NO_CALLBACK)
const SubMenuInfo minfoMoreItems = { "More Items", 4, 0xffff, 0, NO_CALLBACK };
BackMenuItem menuBackMoreItems(fnMoreItemsRtCall, &menuMoreItemsOptions);
SubMenuItem menuMoreItems(&minfoMoreItems, &menuBackMoreItems, &menuRuntimes);
RENDERING_CALLBACK_NAME_INVOKE(fnLgeNumRtCall, largeNumItemRenderFn, "Lge Num", 6, largeNumDidChange)
EditableLargeNumberMenuItem menuLgeNum(fnLgeNumRtCall, LargeFixedNumber(9, 3, 0U, 0U, false), 3, true, &menuMoreItems);
const AnalogMenuInfo minfoHalves = { "Halves", 2, 4, 255, NO_CALLBACK, 0, 2, "dB" };
AnalogMenuItem menuHalves(&minfoHalves, 0, &menuLgeNum);
const AnalogMenuInfo minfoDecimal = { "Decimal", 1, 2, 1000, decimalDidChange, 0, 10, "d" };
AnalogMenuItem menuDecimal(&minfoDecimal, 0, &menuHalves);

void setupMenu() {
    // First we set up eeprom and authentication (if needed).
    menuMgr.setEepromRef(&glI2cRom);
    authManager.initialise(menuMgr.getEepromAbstraction(), 150);
    menuMgr.setAuthenticator(&authManager);
    // Code generated by plugins.
    gfx.begin();
    renderer.setUpdatesPerSecond(10);
    switches.init(ioexp_myIoOverI2c, SWITCHES_POLL_EVERYTHING, true);
    menuMgr.initForEncoder(&renderer, &menuDecimal, 0, 1, 2);
    renderer.setTitleMode(BaseGraphicalRenderer::TITLE_ALWAYS);
    renderer.setUseSliderForAnalog(false);
    installMonoInverseTitleTheme(renderer, MenuFontDef(nullptr, 1), MenuFontDef(u8g2_font_prospero_bold_nbp_tr, 1), true);
}

