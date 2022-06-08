#include "StaticObjetos.h"

GerenciadorDeColisao StaticObjetos::gerenciador;

GerenciadorDeColisao* StaticObjetos::getGDC()
{
    return &gerenciador;
}
