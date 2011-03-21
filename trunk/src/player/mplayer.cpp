#include "player.h"

int main () {
	Area rumah(0);
	Area lahan(1);
	Area toko(2);
	string a;
	int i;
	Player manusia(&rumah,2000,"man");
	cout << manusia.getName() << endl;
	cout << manusia.getMoney() << endl;
	for (int i = 1; i <= 5; i++) {
		manusia.move(2);
	}
	manusia.setMoney(3000);
	cout << manusia.getMoney() << endl;
	manusia.teleport(&lahan);
	for (int i = 1; i <= 5; i++) {
		manusia.move(2);
	}
	manusia.plow();
	if (manusia.getFrontGrid()->getFase() == 0) {
		cout << "tanah telah tercangkul" << endl;
	} else {
		cout << "tanah gagal tercangkul" << endl;
	}
	cout << "masukkan barang yang ingin dibeli : ";
	cin >> a;
	cout << "masukkan jumlah yang ingin dibeli (>2): ";
	cin >> i;
	manusia.buyItem(a,i);
	cout << "uang : " << manusia.getMoney() << endl;
	manusia.put(0,1);
	if (manusia.getFrontGrid()->getType() == 4) {
		cout << "tanaman telah berhasil tertanam" << endl;
	} else {
		cout << "gagal menanam tanaman" << endl;
	}
	manusia.water();
	if (manusia.getFrontGrid()->getFase() % 2 == 1) {
		cout << "tanah telah berhasil disiram" << endl;
	} else {
		cout << "gagal menyiram tanah" << endl;
	}
	cout << "memakan bibit: " << endl;
	manusia.eat(0);
	cout << "kondisi : ";
	if (manusia.getStatus() == 0) {
		cout << "normal" << endl;
	} else if (manusia.getStatus() == 1) {
		cout << "paralyzed" << endl;
	} else if (manusia.getStatus() == 2) {
		cout << "poisoned" << endl;
	} else if (manusia.getStatus() == 3) {
		cout << "full power" << endl;
	} else if (manusia.getStatus() == 4) {
		cout << "sick" << endl;
	}
	manusia.sellItem(0,1);
	cout << "uang : " << manusia.getMoney() << endl;
	cout << "barang berhasil terjual" << endl;
	return 0;
}