#include "../../formas/forma.h"
#include "../../pontos/ponto3.h"
#include "toroide.h"
#include "../../pontos/ponto.h"
#include "../../utils/Vec3.h"

/**
 * @brief Construtor do sólido Cilindro
 * 
 * @param posicao Ponto do centro da base
 * @param lod Nivel de detalhe
 * @param Altura Altura do cilindro
 * 
 * @author Fernanda Martins
 */

Toroide::Toroide(Ponto3 posicao, int lod, int Altura)
:Forma(posicao,1)
{
    LOD = lod;
    Ponto3 temp{0,(double)Altura,0};
    altura = temp;
    quantidadePontos =  50;
    calcular_pontos_base();
    calcular_pontos_3D();
    projecao = camera->projetar(pontos,quantidadePontos);
}

/**
 * @brief Calcula os pontos do cilindro
 * 
 * @author Fernanda Martins
 */

void Toroide::calcular_pontos_base()
{
    Ponto3* pontosTemp = (Ponto3*)malloc(sizeof(Ponto3) * 5);  

    int raio = 1, p = 0;
    double x,z, y, tmp;
    
    int angulo = 0;
    int angulo1 = 0;
    int posicaoArray = 0; 


    for( ; angulo < 360 ; angulo += 360 / (10), p+=5){
        x = raio * cos( angulo * M_PI / 180 );
        z = raio * sin( angulo * M_PI / 180);
        Ponto3 ponto{x,posicao.y,z};
        for ( ; posicaoArray < 5; posicaoArray+=1)
            pontosTemp[posicaoArray+p] = criar_circulos(ponto)[posicaoArray];

    }
    
    //Todos os pontos são armazenados em ponto_base
    pontos_base = pontosTemp;
}

/**
 * @brief Desenha as ligações entre os pontos
 * 
 * @param window Janela 
 * 
 * @author Fernanda Martins
 */

void Toroide::desenhar(Window &window)
{
    calcular_pontos_3D();
    projecao = camera->projetar(pontos,quantidadePontos);

    for( int ponto = 0 ; ponto < quantidadePontos-1; ponto++ ){
            window.desenha(projecao[ponto],projecao[ponto+1]);
    }
}

Ponto3* Toroide::criar_circulos(Ponto3 centro){
    Ponto3* pontosTemp = (Ponto3*)malloc(sizeof(Ponto3) * 5); 
    // Vec3 vetor{centro, posicao};
    double angulo = 0;
    double y, x, z;
    int i = 0;

    for( ; angulo < 360 ; angulo += 360 / (5), i+=1){
            x = 1 * cos( angulo * M_PI / 180 );
            z = 1 * sin( angulo * M_PI / 180);
            Ponto3 ponto{x,centro.y,z};
            pontosTemp[i] = ponto;
            cout << pontosTemp[i] << endl;
        }
    return pontosTemp;

}

/**
 * @brief Muda tamanho de uma das bases 
 * 
 * @param lado Qual base sofre aumento, se par é a base superior, caso contrario é a base inferior
 * @param tamanho Aumenta ou diminui de acordo com proporção
 * 
 * @author Fernanda Martins
 */

// void Toroide::mudar_base(size_t lado, double tamanho){
//     double x,z, tmp;
    
//     int angulo = 0;
//     int posicaoArray = 0;     
    
//         for( ; angulo < 360 ; angulo += 360 / (quantidadePontos/2), posicaoArray+=2){
//             x = tamanho * cos( angulo * M_PI / 180 );
//             z = tamanho * sin( angulo * M_PI / 180);
            
//             if (lado%2 == 1){
//                 Ponto3 ponto{x,posicao.y,z};
//                 pontos_base[posicaoArray] = ponto;
//             }
//             else{
//                 tmp = posicao.y + altura.y;
//                 Ponto3 ponto{x,tmp,z};
//                 pontos_base[posicaoArray+1] = ponto;
//             }
//         }
// }

/**
 * @brief Definir o nível de detalhe
 * 
 * @param lod nível de detalhe
 * 
 * @author José Mateus
 */

void Toroide::setLOD(int lod){
    if(lod){
        if(LOD<360){
            while(true){                
                LOD++;
                if(360%LOD==0){
                    break;
                }
            }
        }
    }
    else{
        if(LOD>3){
            while(true){
                LOD--;
                if(360%LOD==0){
                    break;
                }
            }        
        }
    }

    quantidadePontos = LOD;    
    calcular_pontos_base();

    Ponto3 anguloAntigo = Ponto3(angulo.x,angulo.y,angulo.z);
    angulo.x = 0;
    angulo.y = 0;
    angulo.z = 0;

    girar(anguloAntigo.x,anguloAntigo.y,anguloAntigo.z);

    calcular_pontos_3D();
    projecao = camera->projetar(pontos,quantidadePontos);
    
}

/**
 * @brief Retornar o nível de detalhe
 * 
 * @param lod nível de detalhe
 * 
 * @author José Mateus
 */

int Toroide::getLOD()
{
    return LOD;
}

ostream & operator<< (ostream &out, const Toroide &p)
{
    return out;
}