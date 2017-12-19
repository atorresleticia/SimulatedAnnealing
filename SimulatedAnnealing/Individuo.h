﻿#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#pragma once
#include <string>

class individuo
{
public:

	~individuo() = default;
	individuo() = default;
	void gera_individuo(int tamanho_individuo);
	void set_aptidao(std::string cromossomo);
	void set_aptidao(int aptidao);
	individuo get_melhor(individuo& a);
	void set_cromossomo(std::string cromossomo);


	std::string get_cromossomo() const
	{
		return cromossomo_;
	}

	int get_tamanho_individuo() const
	{
		return tamanho_individuo_;
	}

	int get_aptidao() const
	{
		return aptidao_;
	}

	void set_tamanho_individuo(int tamanho)
	{
		tamanho_individuo_ = tamanho;
	}

private:
	std::string cromossomo_;
	int tamanho_individuo_;
	int aptidao_;
};


#endif

