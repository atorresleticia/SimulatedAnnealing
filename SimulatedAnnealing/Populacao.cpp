﻿#include "stdafx.h"
#include "populacao.h"

populacao::populacao(int tamanho_populacao, int tamanho_cromossomo, bool gera_individuos)
{
	tamanho_populacao_ = tamanho_populacao;
	individuos_ = new individuo[tamanho_populacao];

	if (gera_individuos)
	{
		for (int i = 0; i < tamanho_populacao_; i++)
		{
			individuo novo;
			novo.gera_individuo(tamanho_cromossomo);
			armazena_individuo(i, novo);
		}
	}
}

individuo populacao::get_melhor() const
{
	individuo melhor = individuos_[0];
	for (int i = 1; i < tamanho_populacao_; i++)
	{
		if (melhor.get_aptidao() <= get_individuo_em(i).get_aptidao())
		{
			melhor = get_individuo_em(i);
		}
	}
	return melhor;
}

individuo populacao::get_melhor(individuo& a, individuo& b)
{
	individuo melhor = a.get_aptidao() > b.get_aptidao() ? a : b;
	return melhor;
}

void populacao::armazena_individuo(int i, individuo x_i) const
{
	individuos_[i].set_tamanho_individuo(x_i.get_tamanho_individuo());
	individuos_[i].set_cromossomo(x_i.get_cromossomo());
}
