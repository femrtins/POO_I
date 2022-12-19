#pragma once
#include<SDL2/SDL.h>
#include <iostream>
#include "../../pontos/ponto3.h"
#include "../../formas/forma.h"
#include "../../utils/janela.h"
#include "../../utils/Vec3.h"
#include "../cone/cone.h"
#include "../cilindro/cilindro.h"

using namespace std;

class Axis : virtual public Forma
{
    private:
        Ponto3 altura;

    public:
        
        // Axis(Ponto3 posicao);
        Axis(Ponto3 posicao, double tamanho);
        
        void desenhar(Window &window);
        void calcular_pontos_base();
};

ostream & operator<<(ostream &out, const Axis &p);