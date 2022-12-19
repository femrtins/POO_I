.PHONY: clean doxygen

CXX=g++ -g
RM=rm

# receita para gerar o binário final teste_PROJECAO
teste: bin/janela.o bin/ponto.o bin/ponto3.o bin/camera.o bin/forma.o bin/cubo.o bin/esfera.o bin/cilindro.o bin/teste.o bin/Vec3.o bin/cone.o bin/plano.o bin/toroide.o bin/axis.o
	$(CXX) bin/teste.o bin/janela.o bin/ponto.o bin/ponto3.o bin/camera.o bin/forma.o bin/cubo.o bin/esfera.o bin/cilindro.o bin/Vec3.o bin/cone.o bin/plano.o bin/toroide.o  bin/axis.o -o teste -lSDL2

# receita para gerar o (arquivo objeto) teste_PROJECAO.o
bin/teste.o: teste.cpp
	$(CXX) -o bin/teste.o -c teste.cpp -lSDL2


bin/camera.o: utils/camera.cpp utils/camera.h
	$(CXX) -o bin/camera.o -c utils/camera.cpp

bin/axis.o: formas/axis/axis.cpp formas/axis/axis.h
	$(CXX) -o bin/axis.o -c formas/axis/axis.cpp -lSDL2

bin/toroide.o: formas/toroide/toroide.cpp formas/toroide/toroide.h
	$(CXX) -o bin/toroide.o -c formas/toroide/toroide.cpp -lSDL2

bin/cone.o: formas/cone/cone.cpp formas/cone/cone.h
	$(CXX) -o bin/cone.o -c formas/cone/cone.cpp -lSDL2

bin/plano.o: formas/plano/plano.cpp formas/plano/plano.h
	$(CXX) -o bin/plano.o -c formas/plano/plano.cpp -lSDL2

bin/esfera.o: formas/esfera/esfera.cpp formas/esfera/esfera.h
	$(CXX) -o bin/esfera.o -c formas/esfera/esfera.cpp -lSDL2

bin/cubo.o: formas/cubo/cubo.cpp formas/cubo/cubo.h
	$(CXX) -o bin/cubo.o -c formas/cubo/cubo.cpp -lSDL2

bin/cilindro.o: formas/cilindro/cilindro.cpp formas/cilindro/cilindro.h
	$(CXX) -o bin/cilindro.o -c formas/cilindro/cilindro.cpp -lSDL2


# receita para gerar o (arquivo objeto) janela.o
bin/janela.o: utils/janela.cpp utils/janela.h
	$(CXX) -o bin/janela.o -c utils/janela.cpp -lSDL2

# receita para gerar o (arquivo objeto) ponto.o
bin/ponto.o: pontos/ponto.cpp pontos/ponto.h
	$(CXX) -o bin/ponto.o -c pontos/ponto.cpp -lSDL2

# receita para gerar o (arquivo objeto) ponto3.o
bin/ponto3.o: pontos/ponto3.cpp pontos/ponto3.h
	$(CXX) -o bin/ponto3.o -c pontos/ponto3.cpp -lSDL2

bin/forma.o: formas/forma.cpp formas/forma.h
	$(CXX) -o bin/forma.o -c formas/forma.cpp -lSDL2

bin/Vec3.o: utils/Vec3.cpp utils/Vec3.h
	$(CXX) -o bin/Vec3.o -c utils/Vec3.cpp -lSDL2




# receita para apagar arquivos (geralmente são arquivos gerados
# no processo de desenvolvimento)
clean:
	$(RM) -f bin/ponto.o
	$(RM) -f bin/ponto3.o
	$(RM) -f bin/janela.o
	$(RM) -f teste
	$(RM) -f bin/teste.o
	$(RM) -f bin/forma.o
	$(RM) -f bin/cubo.o
	$(RM) -f bin/esfera.o
	$(RM) -f bin/Vec3.o
	$(RM) -f bin/cone.o
	$(RM) -f bin/camera.o
	$(RM) -f bin/cilindro.o

# receita para gerar a documentação, o arquivo Doxyfile está
# configurado para gerar um diretório chamado docs
doc:
	doxygen

# receita para apagar o conteúdo do diretório de documentação
cleandoc:
	$(RM) -fR doc

run:
	./teste
