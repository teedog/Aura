// Localization implementation for Aura
#include "localization.h"

AuraLang aura_language = LANG_EN;

// English strings
static const struct { const char* key; const char* value; } en_strings[] = {
    {"today", "Today"},
    {"feels_like", "Feels Like"},
    {"seven_day_forecast", "SEVEN DAY FORECAST"},
    {"hourly_forecast", "HOURLY FORECAST"},
    {"now", "Now"},
    {"city", "City:"},
    {"search_results", "Search Results"},
    {"save", "Save"},
    {"cancel", "Cancel"},
    {"aura_settings", "Aura Settings"},
    {"brightness", "Brightness:"},
    {"location", "Location:"},
    {"use_f", "Use °F:"},
    {"24hr", "24hr:"},
    {"reset_wifi", "Reset Wi-Fi"},
    {"close", "Close"},
    {"reset", "Reset"},
    {"reset_wifi_confirm", "Are you sure you want to reset Wi-Fi credentials?\n\nYou'll need to reconnect to the Wifi SSID Aura with your phone or browser to reconfigure Wi-Fi credentials."},
    {"wifi_config", "Wi-Fi Configuration:\n\nPlease connect your\nphone or laptop to the\ntemporary Wi-Fi access\npoint Aura\nto configure.\n\nIf you don't see a \nconfiguration screen \nafter connecting,\nvisit http://192.168.4.1\nin your web browser."},
    {NULL, NULL}
};

// German strings
static const struct { const char* key; const char* value; } de_strings[] = {
    {"today", "Heute"},
    {"feels_like", "Gefühlt"},
    {"seven_day_forecast", "7-TAGE-PROGNOSE"},
    {"hourly_forecast", "STUNDENPROGNOSE"},
    {"now", "Jetzt"},
    {"city", "Stadt:"},
    {"search_results", "Suchergebnisse"},
    {"save", "Speichern"},
    {"cancel", "Abbrechen"},
    {"aura_settings", "Aura Einstellungen"},
    {"brightness", "Helligkeit:"},
    {"location", "Ort:"},
    {"use_f", "Nutze °F:"},
    {"24hr", "24h:"},
    {"reset_wifi", "WLAN zurücksetzen"},
    {"close", "Schließen"},
    {"reset", "Zurücksetzen"},
    {"reset_wifi_confirm", "WLAN-Zugangsdaten wirklich zurücksetzen?\n\nSie müssen sich erneut mit dem WLAN Aura verbinden, um die Zugangsdaten zu konfigurieren."},
    {"wifi_config", "WLAN-Konfiguration:\n\nBitte verbinden Sie Ihr\nHandy oder Laptop mit dem\ntemporären WLAN\nAura\nzur Konfiguration.\n\nFalls kein Konfigurationsbildschirm erscheint,\nbesuchen Sie http://192.168.4.1\nin Ihrem Webbrowser."},
    {NULL, NULL}
};

static const char* lookup(const char* key, const struct { const char* key; const char* value; }* table) {
    for (int i = 0; table[i].key != NULL; ++i) {
        if (strcmp(key, table[i].key) == 0) return table[i].value;
    }
    return key;
}

const char* aura_tr(const char* key) {
    switch (aura_language) {
        case LANG_DE: return lookup(key, de_strings);
        case LANG_EN:
        default: return lookup(key, en_strings);
    }
}

void aura_set_language(AuraLang lang) {
    aura_language = lang;
}
