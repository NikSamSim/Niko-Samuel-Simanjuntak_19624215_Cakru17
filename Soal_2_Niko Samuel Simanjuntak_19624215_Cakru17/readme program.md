Penjelasan Kode:


1. Class Robot
   
   a. Masing-masing robot memiliki atribut: name, health, dan attack_power.
   
   b. Metode attack() memungkinkan robot menyerang lawan, dengan damage acak antara 1 hingga attack_power.
   
   c. Metode isDefeated() mengembalikan true jika kesehatan robot sudah 0 atau kurang.
   
   
2. Class Battle
   
   a. Battle diinisialisasi dengan dua robot (robot1 dan robot2) untuk bertarung.
   
   b. Metode start_fight() menjalankan loop pertarungan sampai salah satu robot kalah.
   

3. Class Game
   
   a. Menyimpan daftar robot yang bisa bertarung.
   
   b. Metode add_robot() untuk menambahkan robot ke dalam daftar.
   
   c. Metode start_game() meminta pemain memilih dua robot untuk bertarung dan menjalankan pertarungan dengan metode start_fight().
