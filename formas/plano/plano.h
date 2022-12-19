#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "../forma.h"
#include "../../pontos/ponto3.h"
#include "plano.h"
#include "../../pontos/ponto.h"
#include "../../utils/Vec3.h"
#include "../../utils/janela.h"

using namespace std;

class Plano : virtual public Forma
{
    private:
        int LOD;
        int largura, comprimento;
        
    public:
        
        Plano(Ponto3 posicao, int largura);
        
        void desenhar(Window &window);
        void calcular_pontos_base();
        void revolucao();

        void setLOD(int lod);
        int getLOD();
};

ostream & operator<<(ostream &out, const Plano &p);