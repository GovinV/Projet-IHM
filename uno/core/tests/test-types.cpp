#include "catch.hpp"

#include "../types.h"

bool message_equivalent(Message m1, Message m2)
{
  return m1.num_joueur == m2.num_joueur && m1.type == m2.type;
}

TEST_CASE("Test de la structure InfoPartie", "[TYPES]")
{
  SECTION("Test d'égalité de messages")
  {
    SECTION("Messages equivalents")
    {
      REQUIRE(message_equivalent({DEBUT_PARTIE, 1}, {DEBUT_PARTIE, 1}));
      REQUIRE(message_equivalent({FIN_MANCHE, 3}, {FIN_MANCHE, 3}));
    }

    SECTION("Messages différents")
    {
      REQUIRE_FALSE(message_equivalent({DEBUT_PARTIE, 1}, {DEBUT_PARTIE, 3}));
      REQUIRE_FALSE(message_equivalent({JOUEUR_CHOIX_COULEUR, 1}, {DEBUT_PARTIE, 1}));
      REQUIRE_FALSE(message_equivalent({DEBUT_PARTIE, 3}, {JOUEUR_ACTION, 1}));
    }
  }

  SECTION("Test d'ajout de messages dans une structure InfoPartie")
  {
    InfoPartie infos;

    REQUIRE(infos.messages.empty());
    REQUIRE(infos.nb_messages == 0);
    REQUIRE(infos.num_next_message == 0);

    Message m1, m2;

    m1.num_joueur = 4;
    m1.type = DEBUT_PARTIE;

    m2.num_joueur = 2;
    m2.type = JOUEUR_ACTION;

    infos.add_message(m1);

    CHECK(infos.nb_messages == 1);
    CHECK(infos.num_next_message == 0);
    CHECK(infos.messages.size() == 1);

    infos.add_message(m2);

    CHECK(infos.nb_messages == 2);
    CHECK(infos.num_next_message == 0);
    CHECK(infos.messages.size() == 2);

    CHECK(message_equivalent(infos.messages[infos.num_next_message++], m1));

    infos.add_message({DEBUT_MANCHE, 3});

    CHECK(infos.nb_messages == 3);
    CHECK(infos.num_next_message == 1);
    CHECK(infos.messages.size() == 3);

    CHECK(message_equivalent(infos.messages[infos.num_next_message++], m2));
    CHECK(message_equivalent(infos.messages[infos.num_next_message++], {DEBUT_MANCHE, 3}));
  }
}

TEST_CASE("Test de la génération pseudo-aléatoire", "[TYPES]")
{
  SECTION("Génération d'une suite de nombres")
  {
    std::vector<int> l1;
    u_int seed = time(NULL);

    REQUIRE(l1.empty());

    my_srand(seed);

    for(int i=0; i<10; i++)
    {
      l1.push_back(my_rand());
      if(i>0)
      {
        CHECK(l1[i-1] != l1[i]);
      }
    }

    REQUIRE(l1.size() == 10);

    SECTION("Génération de la même suite de nombres")
    {
      my_srand(seed);

      for(int i=0; i<10; i++)
      {
        CHECK(my_rand() == l1[i]);
      }
    }

    SECTION("Génération d'une suite de nombre différente")
    {
      std::vector<int> l2;

      REQUIRE(l2.empty());

      my_srand(seed+1);

      for(int i=0; i<10; i++)
      {
        l2.push_back(my_rand());
        if(i>0)
        {
          CHECK(l2[i-1] != l2[i]);
        }
      }

      REQUIRE(l1.size() == l2.size());

      CHECK(l1 != l2);
    }
  }
}
