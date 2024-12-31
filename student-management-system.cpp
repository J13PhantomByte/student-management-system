#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Student {
    int id;
    string name;
    string major;
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    void create() {
        Student student;
        cout << "Masukkan ID Mahasiswa: ";
        cin >> student.id;
        cin.ignore(); // Mengabaikan newline setelah memasukkan ID
        cout << "Masukkan Nama Mahasiswa: ";
        getline(cin, student.name);
        cout << "Masukkan Jurusan Mahasiswa: ";
        getline(cin, student.major);
        students.push_back(student);
        cout << "Data mahasiswa berhasil ditambahkan.\n";
    }

    void read() {
        if (students.empty()) {
            cout << "Tidak ada data mahasiswa.\n";
            return;
        }
        cout << "Data Mahasiswa:\n";
        for (const auto& student : students) {
            cout << "ID: " << student.id << ", Nama: " << student.name << ", Jurusan: " << student.major << endl;
        }
    }

    void update() {
        int id;
        cout << "Masukkan ID mahasiswa yang ingin diupdate: ";
        cin >> id;

        for (auto& student : students) {
            if (student.id == id) {
                cout << "Masukkan Nama baru: ";
                cin.ignore();
                getline(cin, student.name);
                cout << "Masukkan Jurusan baru: ";
                getline(cin, student.major);
                cout << "Data mahasiswa berhasil diupdate.\n";
                return;
            }
        }
        cout << "Mahasiswa dengan ID " << id << " tidak ditemukan.\n";
    }

    void remove() {
        int id;
        cout << "Masukkan ID mahasiswa yang ingin dihapus: ";
        cin >> id;

        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Data mahasiswa berhasil dihapus.\n";
                return;
            }
        }
        cout << "Mahasiswa dengan ID " << id << " tidak ditemukan.\n";
    }
};

int main() {
    StudentManagementSystem sms;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Tambah Mahasiswa\n";
        cout << "2. Tampilkan Mahasiswa\n";
        cout << "3. Update Mahasiswa\n";
        cout << "4. Hapus Mahasiswa\n";
        cout << "5. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sms.create();
                break;
            case 2:
                sms.read();
                break;
            case 3:
                sms.update();
                break;
            case 4:
                sms.remove();
                break;
            case 5:
                cout << "Terima kasih! Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 5);

    return 0;
}