# queue-linkedlist
Data Mahasiswa <br>
Problem: fitur delete bisa memilih simpul yang akan dihapus berdasarkan id. <br>
Jika saya memiliki 2 data dan saya ingin menghapus data ke-dua / data terakhir, maka simpul langsung mengarah ke
simpul berikutnya (simpul->next), yang artinya simpul tersebut berisi NULL atau kosong karna saya tidak memiliki simpul lain, simpul ke-3.<br>di sini problemnya, ketika saya ingin menampilkan semua data (display()), saya tidak bisa menampilkan data pertama tadi (karena simpul langsung mengarah ke simpul->next, data tersebut tidak ada), hasilnya "Queue is empty".
