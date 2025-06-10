// Localization support for Aura
// Add more languages as needed

#ifndef AURA_LOCALIZATION_H
#define AURA_LOCALIZATION_H

#include <Arduino.h>

// Supported languages
enum AuraLang {
    LANG_EN = 0,
    LANG_DE = 1
};

// Set default language to English
extern AuraLang aura_language;

// Returns the localized string for the given key
const char* aura_tr(const char* key);

// Set the current language
void aura_set_language(AuraLang lang);

#endif // AURA_LOCALIZATION_H
