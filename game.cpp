class Character {
protected:
	int hp;
	int mana;
	int attack_damage;
	bool dead;
public:
	Character() :hp(100), mana(100),attack_damage(0),dead(false) {}
	virtual ~Character() = default;
	bool isDead()const{
		return dead;
	}
	
	void take_dmg(int damage){
		if (dead)return;
		hp -= damage;
		if (hp <= 0) {
			hp = 0;
			dead = true;
			std::cout << "Game over";
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
	void attack(Character& target)override {
		if (dead)return;
		std::cout << "Swordman attack for" << attack_damage << "HP" << std::endl;
		target.take_dmg(attack_damage);

	}
};
class Mage :public Character{
public:
	Mage() {
		hp = 80;
		mana = 100;
		attack_damage = 15;
	}
}