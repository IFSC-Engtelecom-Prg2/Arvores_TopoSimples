//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include <list>
#include <random>
#include <prglib.h>
#include "questao.h"
#include "gtest/gtest.h"

using namespace std;
using prglib::arvore;

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }

    string mostra(const list<string> & l, char sep=' ') {
        if (l.empty()) return "";

        ostringstream out;

        for (auto & x: l) out << x << sep;
        string res = out.str();
        res.pop_back();
        return res;
    }

    void embaralha(list<string> & l) {
        vector<string> v(l.begin(), l.end());

        shuffle(v.begin(), v.end(), std::default_random_engine(1));

        l.clear();
        for (auto & x: v) l.push_back(x);

    }
};

ostream  & operator<<(ostream & out, list<string> & l) {
    for (auto & x: l) {
        out << x << ",";
    }
    return out;
}

TEST_F(TesteQuestao, OK)
{
        list<string> l, l2;
        arvore<string> arv;

        try {
            arv  = cria_arvore();
            if (arv.vazia()) {
                FAIL() << "== resultado de criaArvore foi árvore vazia !!!" << endl;
            }
        } catch (...) {
            FAIL() << "cria_arvore disparou uma excecao ... ";
            return;
        }

        arv.listePreOrder(l);
        l2.push_back("mar");
        l2.push_back("ferias");
        l2.push_back("areia");
        l2.push_back("luz");
        l2.push_back("praia");
        l2.push_back("onda");
        l2.push_back("sol");

        if (not (l == l2)) {
            string r = "Conteúdo esperado: ";
            ostringstream s1, s2;
            s1 << l2;
            r += s1.str();
            r += "\n\nConteúdo encontrado: ";
            s2 << l;
            r += s2.str();

            FAIL() << "\nÁrvore diferente do esperado. Ao listá-la em pre-order:\n\n" + r;
            return;
        }
    }