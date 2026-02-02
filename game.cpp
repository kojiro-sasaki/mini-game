#include <iostream>

enum class DamageType {
    Physical,
    Fire,
    Mental
};

class Character {
protected:
    int hp;
    int mana;
    int attack_damage;
    bool dead;

public:
    Character()
        : hp(100), mana(100), attack_damage(0), dead(false) {
    }

    virtual ~Character() = default;

    bool isDead() const {
        return dead;
    }

    void take_dmg(int damage, DamageType type) {
        if (dead) return;

        switch (type) {
        case DamageType::Physical:
            break;

        case DamageType::Fire:
            damage -= 5;
            if (damage < 0) damage = 0;
            break;

        case DamageType::Mental:
            break;
        }

        hp -= damage;

        std::cout << "Took " << damage << " damage. HP left: " << hp << "\n";

        if (hp <= 0) {
            hp = 0;
            dead = true;
            std::cout << "Character died\n";
        }
    }

    virtual void attack(Character& target) = 0;
};

class Swordman : public Character {
public:
    Swordman() {
        hp = 100;
        mana = 50;
        attack_damage = 25;
    }

    void attack(Character& target) override {
        if (dead) return;

        std::cout << "Swordman attacks for "
            << attack_damage << " physical damage\n";

        target.take_dmg(attack_damage, DamageType::Physical);
    }
};

class Mage : public Character {
public:
    Mage() {
        hp = 80;
        mana = 100;
        attack_damage = 10; 
    }

    void attack(Character& target) override {
        if (dead) return;

        std::cout << "Mage hits with staff for "
            << attack_damage << " physical damage 🪄\n";

        target.take_dmg(attack_damage, DamageType::Physical);
    }

    void castFireball(Character& target) {
        const int manaCost = 30;
        const int fireballDamage = 35;

        if (dead) return;

        if (mana < manaCost) {
            std::cout << "Not enough mana!\n";
            return;
        }

        mana -= manaCost;

        std::cout << "Mage casts Fireball for "
            << fireballDamage << " fire damage\n";

        target.take_dmg(fireballDamage, DamageType::Fire);
    }
};

class Duch : public Character {
public:
    Duch() {
        hp = 60;
        mana = 50;
        attack_damage = 5;
    }

    void attack(Character& target) override {
        if (dead) return;

        std::cout << "Duch attacks for "
            << attack_damage << " physical damage \n";

        target.take_dmg(attack_damage, DamageType::Physical);
    }

    void mentalDeath(Character& target) {
        const int manaCost = 20;
        const int danteDamage = 100;

        if (dead) return;

        if (mana < manaCost) {
            std::cout << "Not enough mana for dante attack!\n";
            return;
        }

        mana -= manaCost;

        std::cout << "Duch casted his ULTY !!!! CRITICAL DAMAGE :"<< danteDamage <<std::endl;

        target.take_dmg(danteDamage, DamageType::Mental);
    }
};

int main() {
    Swordman warrior;
    Duch duch;
    duch.mentalDeath(warrior);
}
