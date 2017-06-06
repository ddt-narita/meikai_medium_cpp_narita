/* 演習06-03 header
 * じゃんけんのプレーヤーを表す抽象クラス、そこから派生する人間、コンピュータークラスの作成
 * 作成日：6月6日
 * 作成者：成田修之
 */

#ifndef ___Janken
#define ___Janken

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<typeinfo>
#include<string>
#include<sstream>

class Player {
protected:
//じゃんけんの手のデータ
	int hand;

public:
	//コンストラクタ
	Player(int h):hand(h){

	}

	//複製する仮想関数
	virtual Player* clone() const = 0;

	//純粋仮想デストラクタ
	virtual ~Player() = 0;

	//手のゲッター
	int get_hand() const {
		return hand;
	}

	//セッター
	void set_hand(int h) {
		hand = (h >= 0 && h <= 2) ? h : -1;
	}

	//文字列表現にして返却する純粋仮想関数
	virtual std::string to_string()const = 0;

	//デバッグ時用の情報を表示する関数
	void debug()const;
};

//仮想デストラクタの定義
inline Player::~Player(){

}

//デバッグ時用の情報を表示する関数
inline void Player::debug()const
{
	std::cout << "--デバッグ情報--\n";
	std::cout << "型：" << typeid(*this).name() << "\n";
	std::cout << "アドレス：" << this << "\n";
}

//人間プレーヤークラス
class HumanPlayer:public Player {
public:

	//コンストラクタ
	HumanPlayer(int h):Player(h) {

	}

	//複製を作ってそのオブジェクトへのポインタを返却する関数
	HumanPlayer* clone() const{
		return new HumanPlayer(hand);
	}

	//文字列表現を返却する関数
	virtual std::string to_string() const {
		std::ostringstream os;
		os << "HumanPlayer(hand：" << (hand == 0 ? "グー" : (hand == 1) ? "チョキ" : "パー") << ")\n";
		return os.str();
	}

};

//コンピュータープレイヤークラス
class ComputerPlayer:public Player {

public:

	//０から2のランダムな値でPlayerのコンストラクタを呼びだすコンストラクタ
	ComputerPlayer():Player(rand() % 3) {

	}

	//複製を作ってそれを指すポインタを返却する関数
	ComputerPlayer* clone() const {
		return new ComputerPlayer();
	}

	//文字列表現にして返却する関数
	std::string to_string() const {
		std::ostringstream os;
		os << "ComputerPlayer(hand：" << (hand == 0 ? "グー" : (hand == 1) ? "チョキ" : "パー") << ")\n";
		return os.str();
	}
};


//挿入子の多重定義
inline std::ostream& operator<<(std::ostream& os, const Player& p)
{
	//文字列表現を返却する
	return os << p.to_string();
}

#endif
