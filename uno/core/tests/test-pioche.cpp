#include "catch.hpp"

#include "../pioche.h"


bool paquet_identique(std::vector<Carte *> paquet1, std::vector<Carte *> paquet2)
{
  int taille1 = paquet1.size();
  int taille2 = paquet2.size();

  bool identique = true;

  if(taille1 != taille2)
  {
    identique = false;
  }
  else
  {
    for(int i=0; i<taille1; i++)
    {
      if(!egalite_cartes(paquet1[i], paquet2[i]))
      {
        identique = false;
        break;
      }
    }
  }

  return identique;
}

TEST_CASE("Test de la pioche", "[PIOCHE]")
{
  Pioche p;

  REQUIRE(p.pile.size() == 108);
  REQUIRE(p.tas.empty());

  SECTION("Test du mélange de la pile")
  {
    Pioche p2;

    REQUIRE(p2.pile.size() == 108);
    REQUIRE(p2.tas.empty());

    REQUIRE(paquet_identique(p.pile, p2.pile));
    REQUIRE(paquet_identique(p.tas, p2.tas));

    SECTION("Mélanger une pioche")
    {
      my_srand(10);
      p.melanger();

      REQUIRE(p.pile.size() == 108);
      REQUIRE(p.tas.empty());

      CHECK_FALSE(paquet_identique(p.pile, p2.pile));
      CHECK(paquet_identique(p.tas, p2.tas));

      SECTION("Réaliser le même mélange sur deux pioches identiques")
      {
        my_srand(10);
        p2.melanger();

        REQUIRE(p2.pile.size() == 108);
        REQUIRE(p2.tas.empty());

        CHECK(paquet_identique(p.pile, p2.pile));
        CHECK(paquet_identique(p.tas, p2.tas));
      }

      SECTION("Réaliser des mélanges différents sur deux pioches identiques")
      {
        my_srand(11);
        p2.melanger();

        REQUIRE(p2.pile.size() == 108);
        REQUIRE(p2.tas.empty());

        CHECK_FALSE(paquet_identique(p.pile, p2.pile));
        CHECK(paquet_identique(p.tas, p2.tas));
      }
    }
  }

  SECTION("Piocher et poser des cartes")
  {
    SECTION("Ne rien piocher et ne rien jouer")
    {
      SECTION("Remettre les cartes du tas dans la pile")
      {
        REQUIRE(p.pile.size() == 108);
        REQUIRE(p.tas.empty());

        p.ramasser();

        CHECK(p.pile.size() == 108);
        CHECK(p.tas.empty());
      }
    }

    SECTION("Piocher 108 cartes")
    {
      REQUIRE(p.pile.size() == 108);
      REQUIRE(p.tas.empty());

      Carte *c;

      for(int i=1; i<=108; i++)
      {
        c = p.tirer_carte();
        p.poser(c);
        CHECK(p.pile.size()+i == 108);
        CHECK(p.tas.size() == i);
      }

      SECTION("Tirer plus que 108 cartes dans la partie")
      {
        REQUIRE(p.pile.empty());
        REQUIRE(p.tas.size() == 108);

        c = p.tirer_carte();
        p.poser(c);

        CHECK(p.pile.size() == 107);
        CHECK(p.tas.size() == 1);
      }

      SECTION("Remettre les cartes du tas dans la pile")
      {
        REQUIRE(p.pile.empty());
        REQUIRE(p.tas.size() == 108);

        p.ramasser();

        CHECK(p.pile.size() == 108);
        CHECK(p.tas.empty());
      }
    }
  }
}
