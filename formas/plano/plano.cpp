#include "../forma.h"
#include "../../pontos/ponto3.h"
#include "plano.h"
#include "../../pontos/ponto.h"
#include "../../utils/Vec3.h"

/**
 * @brief Construtor do Plano Quadrado
 * 
 * @param posicao Ponto do centro do plano
 * @param largura Largura do plano
 * 
 * @author Fernanda Martins
 */

Plano::Plano(Ponto3 posicao, int largura)
:Forma(posicao,1), largura{largura}
{
    quantidadePontos = largura*largura;

    calcular_pontos_base();
    calcular_pontos_3D();
    projecao = camera->projetar(pontos,quantidadePontos);

}

/**
 * @brief Calcula os pontos do plano
 * 
 * @author Fernanda Martins
 */

void Plano::calcular_pontos_base()
{
    int a = 0;
    Ponto3* pontosTemp = (Ponto3*)malloc(sizeof(Ponto3) * quantidadePontos); 
    for (double i = 0; i < largura; i++){
        for (double j= 0; j < largura; j++){
            Ponto3 ponto{i-(largura/2),0,j-(largura/2)};
            pontosTemp[a] = ponto;
            a++;
        }
    }
    //Todos os pontos são armazenados em ponto_base
    pontos_base = pontosTemp;
}

/**
 * @brief Desenha as ligações entre os pontos do plano que formam angulos de 90 graus
 * 
 * @param window Janela 
 * 
 * @author Fernanda Martins
 */

void Plano::desenhar(Window &window)
{
    calcular_pontos_3D();
    projecao = camera->projetar(pontos,quantidadePontos);
    int ponto = 0;
    int i = 1;

    for( ; ponto < quantidadePontos-1; ponto++ ){
        if (i != largura){
            window.desenha(projecao[ponto],projecao[ponto+1],corR,corG,corB);
            i++;
        }
        else {
            window.desenha(projecao[ponto],projecao[ponto+largura],corR,corG,corB);
            i = 1;
        }            
    }
    int x = quantidadePontos-largura;
    ponto = 0;
    for( ; ponto < largura; ponto++ ){
        window.desenha(projecao[ponto],projecao[x],corR,corG,corB);
        x = x+1;
    }
}

ostream & operator<< (ostream &out, const Plano &p)
{
    return out;
}