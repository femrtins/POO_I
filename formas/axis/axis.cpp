#include "../../formas/forma.h"
#include "../cone/cone.h"
#include "../cilindro/cilindro.h"
#include "../cubo/cubo.h"
#include "../../pontos/ponto3.h"
#include "axis.h"
#include "../../pontos/ponto.h"
#include "../../utils/Vec3.h"

/**
 * @brief Construtor do sólido Cilindro
 * 
 * @param posicao Ponto do centro do circulo
 * @param lod Nivel de detalhe
 * @param Altura Altura do cilindro
 * 
 * @author Fernanda Martins
 */

Axis::Axis(Ponto3 posicao, double tamanho)
:Forma(posicao, tamanho)
{
    Ponto3 temp{0,(double)tamanho,0};
    altura = temp;
    calcular_pontos_base();
}

void Axis::calcular_pontos_base()
{
    Ponto3* pontosTemp = (Ponto3*)malloc(sizeof(Ponto3) * 100); 
    Cone cone{posicao, 20, static_cast<int>(tamanho)};
    Cilindro cilindro{posicao, 20, static_cast<int>(tamanho)};
    for (int i =0; i < 21; i++){
        pontosTemp[i] = cone.pontos_base[i];
        cout << pontosTemp[i] << endl;
    }
    for (int i =21; i < 61; i++){
        pontosTemp[i] = cilindro.pontos_base[i];
        cout << pontosTemp[i] << endl;
    }
    pontos_base = pontosTemp;
}

void Axis::desenhar(Window &window)
{    
    Ponto3 p{posicao.x,posicao.y+tamanho,posicao.z};
    Ponto3 p1{posicao.x,posicao.y-0.1,posicao.z+tamanho};
    Ponto3 p2{posicao.x+2*tamanho,posicao.y-0.1,posicao.z};
    Ponto3 q{posicao.x,posicao.y,posicao.z};
    
    Cone cone{p, 20, static_cast<int>(tamanho)};  
    Cone cone1{p1, 20, static_cast<int>(tamanho)}; 
    Cone cone2{p2, 20, static_cast<int>(tamanho)};  

    Cilindro cilindro{q, 20, static_cast<int>(tamanho)};
    Cilindro cilindro1{q, 20, static_cast<int>(tamanho)};
    Cilindro cilindro2{q, 20, static_cast<int>(tamanho)};

    cilindro.mudar_base(0,0.1,true);
    cilindro.mudar_base(1,0.1,true);
    cilindro1.mudar_base(0,0.1,true);
    cilindro1.mudar_base(1,0.1,true);
    cilindro2.mudar_base(0,0.1,true);
    cilindro2.mudar_base(1,0.1,true);    
    
    // Cilindro cilindro2{cilindro};

    cone.mudar_base(0.2, true); 
    cone1.mudar_base(0.2, true); 
    cone2.mudar_base(0.2, true);     
    
    cone1.girar(0,-90,0);
    cone2.girar(0,0,90);
    // cone.desenhar(window);
    // cone1.desenhar(window);
    // cone2.desenhar(window);

    cilindro.girar(0,0,90);
    // cilindro1.girar(0,90,0);
    cilindro2.girar(0,90,0);

    cilindro.desenhar(window);    
    cilindro1.desenhar(window);    
    cilindro2.desenhar(window);
    
}


ostream & operator<< (ostream &out, const Axis &p)
{
    return out;
}