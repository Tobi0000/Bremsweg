#include "libbremsweg.h"

double Normfallbeschleunigung = 9.80665;
double Haftreibungszahl = 0.0;


Bremsweg::Bremsweg()
:untergrundfaktor(1.0), geschwindigkeit(0.0), bremsweg(0.0), gefahrenbremsung (1), fahrzeug("PkW")
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
    if (fahrzeug == "PkW")
    {
        Haftreibungszahl = 0.8;
        double bremsbeschleunigung = Haftreibungszahl * Normfallbeschleunigung;
        double bremszeit = (geschwindigkeit/3.6)/bremsbeschleunigung;
        double reaktionsweg = geschwindigkeit/10*3;
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
        double bremsbeschleunigung = Haftreibungszahl * Normfallbeschleunigung;
        double bremszeit = (geschwindigkeit/3.6)/bremsbeschleunigung;
        bremsweg = (round((0.5*bremsbeschleunigung*bremszeit*bremszeit)*untergrundfaktor*10))/10;
    }
    else if (fahrzeug == "Zug")
    {
        Haftreibungszahl = 0.18;
        double bremsbeschleunigung = Haftreibungszahl * Normfallbeschleunigung;
        double bremszeit = (geschwindigkeit/3.6)/bremsbeschleunigung;
        bremsweg = (round((0.5*bremsbeschleunigung*bremszeit*bremszeit)*untergrundfaktor*10))/10;
    }
}

double Bremsweg::BremswegAbfragen() const
{
    return bremsweg;
}
