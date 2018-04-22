#include "catch.hpp"

#include "../../core/carte.h"

TEST_CASE("Test des cartes", "[Carte]")
{

  std::vector<Carte *> liste_cartes(15);

  liste_cartes[0] = new Carte(ROUGE, NUMERO, 1);

  liste_cartes[1] = new Carte(ROUGE, NUMERO, 1);
  liste_cartes[2] = new Carte(VERT, NUMERO, 1);
  liste_cartes[3] = new Carte(BLEU, NUMERO, 1);
  liste_cartes[4] = new Carte(JAUNE, NUMERO, 1);

  liste_cartes[5] = new Carte(ROUGE, NUMERO, 8);

  liste_cartes[6] = new Carte(ROUGE, INVERSION, VALEUR_INVERSION);
  liste_cartes[7] = new Carte(VERT, TA_GUEULE, VALEUR_TA_GUEULE);
  liste_cartes[8] = new Carte(BLEU, PLUS_DEUX, VALEUR_PLUS_DEUX);
  liste_cartes[9] = new Carte(JAUNE, INVERSION, VALEUR_INVERSION);

  liste_cartes[12] = new Carte(JAUNE, INVERSION, VALEUR_INVERSION);

  liste_cartes[10] = new Carte(NOIR, JOKER, VALEUR_JOKER);
  liste_cartes[11] = new Carte(NOIR, PLUS_QUATRE, VALEUR_PLUS_QUATRE);

  liste_cartes[13] = new Carte(ROUGE, TA_GUEULE, VALEUR_TA_GUEULE);
  liste_cartes[14] = new Carte(ROUGE, PLUS_DEUX, VALEUR_PLUS_DEUX);


  /** Verification des attributs **/

  REQUIRE(liste_cartes[0]->couleur == ROUGE);
  REQUIRE(liste_cartes[0]->type == NUMERO);
  REQUIRE(liste_cartes[0]->valeur == 1);
  REQUIRE(liste_cartes[0]->description == "Numero 1 (Rouge)");

  REQUIRE(liste_cartes[7]->couleur == VERT);
  REQUIRE(liste_cartes[7]->type == TA_GUEULE);
  REQUIRE(liste_cartes[7]->valeur == VALEUR_TA_GUEULE);
  REQUIRE(liste_cartes[7]->description == "Ta gueule (Vert)");

  REQUIRE(liste_cartes[8]->couleur == BLEU);
  REQUIRE(liste_cartes[8]->type == PLUS_DEUX);
  REQUIRE(liste_cartes[8]->valeur == VALEUR_PLUS_DEUX);
  REQUIRE(liste_cartes[8]->description == "+2 (Bleu)");

  REQUIRE(liste_cartes[9]->couleur == JAUNE);
  REQUIRE(liste_cartes[9]->type == INVERSION);
  REQUIRE(liste_cartes[9]->valeur == VALEUR_INVERSION);
  REQUIRE(liste_cartes[9]->description == "Inversion (Jaune)");

  REQUIRE(liste_cartes[10]->couleur == NOIR);
  REQUIRE(liste_cartes[10]->type == JOKER);
  REQUIRE(liste_cartes[10]->valeur == VALEUR_JOKER);
  REQUIRE(liste_cartes[10]->description == "Joker (Noir)");

  REQUIRE(liste_cartes[11]->couleur == NOIR);
  REQUIRE(liste_cartes[11]->type == PLUS_QUATRE);
  REQUIRE(liste_cartes[11]->valeur == VALEUR_PLUS_QUATRE);
  REQUIRE(liste_cartes[11]->description == "+4 (Noir)");


  SECTION("Test d'égalité entre deux cartes")
  {
    SECTION("Même cartes")
    {
      CHECK(egalite_cartes(liste_cartes[0], liste_cartes[1]));
      CHECK(egalite_cartes(liste_cartes[9], liste_cartes[12]));
    }

    SECTION("Couleur différentes")
    {
      CHECK_FALSE(egalite_cartes(liste_cartes[1], liste_cartes[2]));
      CHECK_FALSE(egalite_cartes(liste_cartes[1], liste_cartes[3]));
      CHECK_FALSE(egalite_cartes(liste_cartes[1], liste_cartes[4]));
      CHECK_FALSE(egalite_cartes(liste_cartes[2], liste_cartes[3]));
      CHECK_FALSE(egalite_cartes(liste_cartes[2], liste_cartes[4]));
      CHECK_FALSE(egalite_cartes(liste_cartes[3], liste_cartes[4]));
    }

    SECTION("Type différent")
    {
      CHECK_FALSE(egalite_cartes(liste_cartes[1], liste_cartes[6]));
      CHECK_FALSE(egalite_cartes(liste_cartes[2], liste_cartes[7]));
      CHECK_FALSE(egalite_cartes(liste_cartes[3], liste_cartes[8]));
      CHECK_FALSE(egalite_cartes(liste_cartes[4], liste_cartes[9]));
      CHECK_FALSE(egalite_cartes(liste_cartes[10], liste_cartes[11]));
    }

    SECTION("Valeur différentes")
    {
      CHECK_FALSE(egalite_cartes(liste_cartes[1], liste_cartes[5]));
    }
  }

  SECTION("Test d'infériorité d'une carte c1 par rapport à une carte c2")
  {
    SECTION("Couleur inférieure (ordre arbitraire)")
    {
      CHECK(comparaison_cartes(liste_cartes[1], liste_cartes[2]));
      CHECK(comparaison_cartes(liste_cartes[2], liste_cartes[3]));
      CHECK(comparaison_cartes(liste_cartes[3], liste_cartes[4]));
      CHECK(comparaison_cartes(liste_cartes[4], liste_cartes[10]));
    }

    SECTION("Couleur supérieure (ordre arbitraire)")
    {
      CHECK_FALSE(comparaison_cartes(liste_cartes[2], liste_cartes[1]));
      CHECK_FALSE(comparaison_cartes(liste_cartes[3], liste_cartes[2]));
      CHECK_FALSE(comparaison_cartes(liste_cartes[4], liste_cartes[3]));
      CHECK_FALSE(comparaison_cartes(liste_cartes[10], liste_cartes[4]));
    }

    SECTION("Mếme couleur")
    {
      SECTION("Type inférieur")
      {
        CHECK(comparaison_cartes(liste_cartes[1], liste_cartes[6]));
        CHECK(comparaison_cartes(liste_cartes[6], liste_cartes[13]));
        CHECK(comparaison_cartes(liste_cartes[13], liste_cartes[14]));
        CHECK(comparaison_cartes(liste_cartes[10], liste_cartes[11]));
      }

      SECTION("Type supérieur")
      {
        CHECK_FALSE(comparaison_cartes(liste_cartes[6], liste_cartes[1]));
        CHECK_FALSE(comparaison_cartes(liste_cartes[13], liste_cartes[6]));
        CHECK_FALSE(comparaison_cartes(liste_cartes[14], liste_cartes[13]));
        CHECK_FALSE(comparaison_cartes(liste_cartes[11], liste_cartes[10]));
      }

      SECTION("Même type")
      {
        SECTION("Valeur inférieure")
        {
          CHECK(comparaison_cartes(liste_cartes[1], liste_cartes[5]));
        }

        SECTION("Valeur supérieure ou égale")
        {
          CHECK_FALSE(comparaison_cartes(liste_cartes[5], liste_cartes[1]));
        }
      }
    }
  }

  for(u_int i=0; i<liste_cartes.size(); i++)
  {
    delete(liste_cartes[i]);
  }

}
