#ifndef item
#define item

class item{
//deskripsi umum kelas item: kelas item digunakan untuk memberikan harga dari item dan tipe dari item.
	//Kamus Global
	private:
		int efekbuah;//efek dari buah yang dimakan player
		int efektime;//lama nya efek dari buah yang dimakan player
		
	public :
		item (); //konstruktor
		item(const item&);//copy konstruktor
		//item &operator=(const item&);//operator assignment
		virtual ~item (); //destructor
		
		int getcost(int );//memberikan harga dari item
		int gettipeItem(int );//memberikan tipe dari item
}
#endif