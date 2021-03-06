// SimulatedAnnealing.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Populacao.h"
#include <ctime>

// Genético
#define TAM_POP 200
#define TAM_CR 512

//Simulated Annealing
#define CONST_R 0.9
#define LS 600
#define LI 25

using namespace std;

individuo s_;

void mutacao(individuo &s)
{
	string cr = s.get_cromossomo();
	
	int pos = rand() % s.get_tamanho_individuo();

	if (cr[pos] == '0')
	{
		cr[pos] = '1';
	}
	else
	{
		cr[pos] = '0';
	}

	s.set_cromossomo(cr);
}

void evolucao(populacao& p, populacao& nova_p, float& t)
{
	for (auto i = 0; i < p.get_tamanho_populacao(); i++)
	{
		s_ = p.get_individuo_em(i);
		mutacao(s_);

		int delta = s_.get_aptidao() - p.get_individuo_em(i).get_aptidao();
		float rnd = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

		if (delta < 0 || rnd < exp(-delta / t))
		{
			nova_p.armazena_individuo(i, s_);
		}
		else
		{
			nova_p.armazena_individuo(i, p.get_individuo_em(i));
		}
	}
	for (int i = 0; i < p.get_tamanho_populacao(); i++)
	{
		p.armazena_individuo(i, nova_p.get_individuo_em(i));
		p.get_individuo_em(i).set_tamanho_individuo(nova_p.get_individuo_em(i).get_tamanho_individuo());
		//cout << "np2:\t" << p.get_individuo_em(i).get_cromossomo() << endl;
	}

	t *= CONST_R;

}

int main()
{
	srand(time(nullptr));

	populacao* pop = new populacao(TAM_POP, TAM_CR, true);
	populacao* nova_p = new populacao(TAM_POP, TAM_CR, true);

	float t = LS;
	const float t_min = LI;

	while (t > t_min)
	{
		evolucao(*pop, *nova_p, t);
	}

	cout << "RESULTADOS: " << endl;
	cout << "Maior aptidao: " << pop->get_melhor().get_aptidao() << endl;
	cout << endl;
	return 0;
}

