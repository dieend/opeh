#ifndef item
#define item


class item{
//desktripsi umum kelas item: kelas item digunakan untuk memberikan harga dari item dan tipe dari item.
	//Kamus Global
	private:
		int cost;//harga dari item
		int tipeItem;//tipe dari item
		int efekbuah;//efek dari buah yang dimakan player
		int efektime;//lama nya efek dari buah yang dimakan player
		
	public :
		item (); //konstruktor
		item(const item&);//copy konstruktor
		item &operator=(const item&);//operator assignment
		virtual ~item (); //destructor
		
		int getcost();//memberikan harga dari item
		int gettipeItem();//memberikan tipe dari item
}
#endif