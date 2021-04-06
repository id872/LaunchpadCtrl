#ifndef SYMBOLGENERATOR_H
#define SYMBOLGENERATOR_H

typedef unsigned char byte;

class SymbolGenerator
{
public:
    static SymbolGenerator& GetInstance()
    {
        static SymbolGenerator instance;
        return instance;
    }

    byte *GetHeart() {return _symbolHeart; }
    byte *GetCandles() {return _candles; }
    byte *GetLights() {return _lights; }
    byte *GetChristmassTree() {return _christmassTree; }
    byte **GetLaunchpadButtons() {return _launchpadButtons; }

private:
    SymbolGenerator();
    ~SymbolGenerator();

    byte *_symbolHeart = nullptr;
    byte *_candles = nullptr;
    byte *_lights = nullptr;
    byte *_christmassTree = nullptr;
    byte **_launchpadButtons = nullptr;

    const int _ledRowCount = 8;

};

#endif // SYMBOLGENERATOR_H
