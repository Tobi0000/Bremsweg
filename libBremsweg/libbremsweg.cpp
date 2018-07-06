#include "libbremsweg.h"

Bremsweg::Bremsweg()
:untergrundfaktor(1.0), geschwindigkeit(0.0), bremsweg(0.0), gefahrenbremsung (1), fahrzeug("PkW")
{
}

Bremsweg::Bremsweg(double untergrundfaktor, double geschwindigkeit, int gefahrenbremsung, std::__cxx11::string fahrzeug)
    :untergrundfaktor(untergrundfaktor), geschwindigkeit(geschwindigkeit), gefahrenbremsung(gefahrenbremsung),fahrzeug(fahrzeug)
{
}

void Bremsweg::GeschwindigkeitSetzen(double neueGeschwindigkeit)
{
    if (geschwindigkeit != neueGeschwindigkeit)
    {
        geschwindigkeit = neueGeschwindigkeit;
        emit WertGeaendert();
    }
}

void Bremsweg::UntergrundfaktorSetzen(double neuerUntergrundfaktor)
{
    if (untergrundfaktor != neuerUntergrundfaktor)
    {
        untergrundfaktor = neuerUntergrundfaktor;
        emit WertGeaendert();
    }
}

void Bremsweg::GefahrenbremsungSetzen(int Gefahrenbremsung)
{
    if (gefahrenbremsung != Gefahrenbremsung)
    {
        gefahrenbremsung = Gefahrenbremsung;
        emit WertGeaendert();
    }
}

void Bremsweg::FahrzeugSetzen(std::string neuesFahrzeug)
{
    if (fahrzeug != neuesFahrzeug)
    {
        fahrzeug = neuesFahrzeug;
        emit WertGeaendert();
    }
}

void Bremsweg::BremswegBerechnen()
{
    double Normfallbeschleunigung = 9.80665;
    double Haftreibungszahl = 0.0;
    double bremsbeschleunigung = 0.0;
    double bremszeit = 0.0;
    double reaktionsweg = geschwindigkeit/3.6;
    if (fahrzeug == "PkW")
    {
        Haftreibungszahl = 0.8;
        bremsbeschleunigung = Haftreibungszahl * Normfallbeschleunigung;
        bremszeit = (geschwindigkeit/3.6)/bremsbeschleunigung;
        if (gefahrenbremsung == 2)
        {
            bremsweg = (round((reaktionsweg+0.5*bremsbeschleunigung*bremszeit*bremszeit)*untergrundfaktor*10))/10;
        }
        else
        {
            bremsweg = (round(((reaktionsweg+0.5*bremsbeschleunigung*bremszeit*bremszeit)*untergrundfaktor*1.5)*10))/10;
        }
    }
    else if (fahrzeug == "Panzer")
    {
        Haftreibungszahl = 1.51;
        bremsbeschleunigung = Haftreibungszahl * Normfallbeschleunigung;
        bremszeit = (geschwindigkeit/3.6)/bremsbeschleunigung;
        bremsweg = (round((reaktionsweg+0.5*bremsbeschleunigung*bremszeit*bremszeit)*untergrundfaktor*10))/10;
    }
    else if (fahrzeug == "Zug")
    {
        Haftreibungszahl = 0.18;
        bremsbeschleunigung = Haftreibungszahl * Normfallbeschleunigung;
        bremszeit = (geschwindigkeit/3.6)/bremsbeschleunigung;
        bremsweg = (round((reaktionsweg+0.5*bremsbeschleunigung*bremszeit*bremszeit)*untergrundfaktor*10))/10;
    }
}

double Bremsweg::BremswegAbfragen() const
{
    return bremsweg;
}
