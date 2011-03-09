#ifndef item
#define item

class Item{
//deskripsi umum kelas item: kelas item digunakan untuk memberikan harga dari item dan tipe dari item.
	//Kamus Global
	private:
		int efekbuah;//efek dari buah yang dimakan player
		int efektime;//lama nya efek dari buah yang dimakan player
		
	public :
		Item (); //konstruktor
		Item(const Item&);//copy konstruktor
		//item &operator=(const item&);//operator assignment
		virtual ~Item (); //destructor
		
		int getcost(int );//memberikan harga dari item
		int gettipeItem(int );//memberikan tipe dari item
};
#endif
