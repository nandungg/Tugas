#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
void gotoxy(int x, int y){
                COORD coord;
                coord.X = x;
                coord.Y = y;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}




//Deklarasi Fungsi
void lihat_data();
void cetak_data();
void tambah_data();
void pilih_data(char mode[50]);
int  cari_data(char kode_matkul[50]);
void edit_data();
void salin_data();
void lihat_riwayat();
void hapus_data();
void search();
void urutkan();

//Deklarasi Struct
struct matakuliah
{
    char kode[50],nama[50],dosen[50],jam[50];
    int sks;
    struct matakuliah *next;
    struct matakuliah *history;
};

struct matakuliah *baru,*head_sort=NULL, *head=NULL, *tail=NULL,*masuk,*masuk2;



void tambah_data()
{
    int x;
    int jumlah_sks,masukan;
    char kode_matakuliah[50],nama_matakuliah[50],dosen_matakuliah,jam_matakuliah[50];

    system("cls");
    printf("\t\t\t Banyak Data yang akan dimasukan : ");
    scanf("%d",&masukan);
    printf("\n");
    for(x=1; x<=masukan; x++)
    {
        printf("\t\t\t Masukan Data Matakuliah[%d]\n",x);
        baru = (struct matakuliah *) malloc(sizeof(struct matakuliah));
    fflush(stdin);
    printf("\t\t\t Masukan kode Matakuliah : ");
    gets(baru->kode);
    printf("\t\t\t Masukan nama Matakuliah : ");
    gets(baru->nama);
    printf("\t\t\t Masukan nama dosen Matakuliah : ");
    gets(baru->dosen);
    printf("\t\t\t Masukan Jam : ");
    gets(baru->jam);
    printf("\t\t\t Masukan Jumlah SKS: ");
    scanf("%d",&baru->sks);
    printf("\n\n");

    baru->next=NULL;
    if(head == NULL)
    {
        head=baru;
        tail=baru;
    }
    else
    {
        tail=head;
        while(tail->next!=NULL)
        {
            tail=tail->next;
        }
        tail->next=baru;

    }
    }getch();
}



void lihat_data()
{
    int x =1;
    if(head != NULL)
    {
        masuk=head;
        while(masuk != NULL)
        {
            printf("\t\t\t Data Matakuliah[%d]\n",x);
            cetak_data();
            x++;
            masuk=masuk->next;
        }
    }
    else
    {
        printf("\t\t\t Belum ada data");
    }
}


void urutkan()
{
    struct matakuliah *i,*j;
    int tempsks;
    char tempkode[30],tempnama[50],tempdosen[50],tempjam[50];
    head_sort=head;
    for(i=head_sort; i->next!=NULL; i=i->next)
    {
        for(j=i->next; j!=NULL; j=j->next)
        {
            if(strcmp(i->kode,j->kode)>0)
            {
                strcpy(tempjam,i->jam);
                strcpy(tempkode,i->kode);
                strcpy(tempnama,i->nama);
                strcpy(tempdosen,i->dosen);
                tempsks=i->sks;
                strcpy(i->jam,j->jam);
                strcpy(i->kode,j->kode);
                strcpy(i->dosen,j->dosen);
                strcpy(i->nama,j->nama);
                i->sks=j->sks;
                strcpy(j->jam,tempjam);
                strcpy(j->kode,tempkode);
                strcpy(j->nama,tempnama);
                strcpy(j->dosen,tempdosen);
                j->sks=tempsks;
            }

        }
    }

}


void cetak_data()
{
    printf("\t\t\t Kode Matakuliah      :\t%s\n",masuk->kode);
    printf("\t\t\t Nama Matakuliah      :\t%s\n",masuk->nama);
    printf("\t\t\t Dosen Matakuliah     :\t%s\n",masuk->dosen);
    printf("\t\t\t Jam Matakuliah       :\t%s\n",masuk->jam);
    printf("\t\t\t Jumlah SKS           :\t%d\n\n",masuk->sks);
}



void pilih_data(char mode[50])
{
    if(head==NULL)
    {
        return;
    }
    int loop = 1;
    char input;
    char nama[50];
    while(loop == 1)
    {
        system("cls");
        printf("\t\t\t Ubah Data Matakuliah\n\n");
        lihat_data();
        printf("\t\t\t Tekan n untuk lanjut");
        input=getche();
        switch(input)
        {
        case'n':
            printf("\n\n\t\t\t Cari Matakuliah berdasarkan Kode: ");
            scanf("%s",nama);
            if(cari_data(nama) ==1)
            {
                if(strcmp(mode,"Ubah") == 0)
                {
                    edit_data();
                }

                else if(strcmp(mode,"Riwayat") == 0)
                {
                    lihat_riwayat();
                }
            }
            else
            {
                printf("\t\t\t Data tidak ditemukan!");
                getch();
            }
        default:
            loop=0;
            break;

        }
    }
}



int cari_data(char nama[50])
{
    int flagIsFound=0;
    masuk=head;
    while(masuk != NULL)
    {
        if(strcmp(masuk->nama,nama) == 0)
        {
            flagIsFound=1;
            break;
        }
        else
        {
            masuk=masuk->next;
        }
    }
    return flagIsFound;
}


void edit_data()
{
    int input;
    char kodeBaru[50],namaBaru[50],dosenBaru[50],jamBaru[50];
    int sksBaru[50];
    int loop =1;
    while(loop == 1)
    {
        system("CLS");
        cetak_data();
        printf("\t\t\t 1. Ganti Kode Matakuliah.\n");
        printf("\t\t\t 2. Ganti Nama Matakuliah.\n");
        printf("\t\t\t 3. Ganti Dosen Matakuliah .\n");
        printf("\t\t\t 4. Ganti Jam Matakuliah.\n");
        printf("\t\t\t 5. Ganti Jumlah SKS Matakuliah.\n");
        printf("\t\t\t 6. KELUAR.\n");
        printf("\t\t\t Masukan Pilihan Anda : ");
        scanf("%d", &input);
        //input=getche();
        printf("\n\n");
        switch(input)
        {
        case 6:
            loop=0;
            break;
        case 1:
            printf("\t\t\t Masukkan Kode Baru: ");
            scanf("%s",kodeBaru);
            salin_data();
            strcpy(masuk->kode,kodeBaru);
            masuk->history=baru;
            break;
        case 2:
            printf("\t\t\t Masukkan Nama Matakuliah: ");
            scanf("%s",namaBaru);
            salin_data();
            strcpy(masuk->nama,namaBaru);
            masuk->history=baru;
            break;
        case 3:
            printf("\t\t\t Masukkan Nama Dosen: ");
            scanf("%s",dosenBaru);
            salin_data();
            strcpy(masuk->dosen,dosenBaru);
            masuk->history=baru;
            break;
        case 4:
            printf("\t\t\t Masukkan Jam Baru: ");
            scanf("%s",jamBaru);
            salin_data();
            strcpy(masuk->jam,jamBaru);
            break;
        case 5:
            printf("\t\t\t Masukkan  Jumlah SKS Baru: ");
            scanf("%d",&masuk->sks);
            masuk->history=baru;
            break;
        }
    }
}


void salin_data()
{
    baru = (struct matakuliah *) malloc(sizeof(struct matakuliah));
    strcpy(baru->kode,masuk->kode);
    strcpy(baru->nama,masuk->nama);
    strcpy(baru->dosen,masuk->dosen);
    strcpy(baru->jam,masuk->jam);
    baru->sks=masuk->sks;
    baru->history=masuk->history;
    baru->next=NULL;
}

void lihat_riwayat()
{
    int x=1;
    system("CLS");
    printf("\t\t\t Riwayat perubahan (terbaru -> terlama)");
    while(masuk != NULL)
    {
        printf("\n\n \t\t\t Data:%d\n",x);
        cetak_data();
        masuk=masuk->history;
        x++;
    }
    getch();

}


void hapus_data()
{
    char del[50];
    int a=0, i;
    lihat_data();
    printf("\n\t\t\t Masukan Kode Matakuliah yang ingin di Hapus : ");
    scanf("%s",&del);

    struct matakuliah *p;
    struct matakuliah *q;
    q=head;
    p=head->next;


    if(strcmp(q->kode,del)==0)
    {
        head=p;
        free(q);
    }

    else
    {
        while(strcmp(p->kode,del)!=0)
        {
            p=p->next;
            q=q->next;
        }
        if(p->next==NULL)
        {
            q->next=NULL;
            free(p);
        }
        else
        {
            q->next=p->next;
            free(p);
        }
    }
}



void search()
{
    char kode_matakuliah[50];

awal :
    printf("\n\n\t\t\t Cari matakuliah berdasarkan Kode : ");
    scanf("%s", &kode_matakuliah);
    if(cari_data(kode_matakuliah) ==1)
    {
        cetak_data();
        getch();
    }
    else
    {
        printf("\t\t\t Data tidak ditemukan!");
        getch();
        system("cls");
        goto awal;
    }
}



int main()
{
    time_t now;
	time(&now);
	system("color F1");
    char user[10];
    char pass[10];
    login:
    system("cls");
  printf("\n\t\t\t\t\t\t\t\t\t\t\t%s", ctime(&now));
  char a[]={"\n\n\n\n\n\t\t\t ====== Program Siasat Universitas Kristen Satya Wacana ======\n"};

for(int i=0;a[i]!=NULL;i++)
{
printf("%c",a[i]);
for(int j=0;j<=9990000;j++)
{
}
}

  printf("\t\t\t ====== ----------------------------------------------- ======\n");
  printf("\t\t\t Username : ");
    scanf("%s", user);
  printf("\t\t\t Password : ");
    scanf("%s", pass);
    if(strcmp(user, "admin")==0 && strcmp(pass, "admin")==0) {
    printf("\n\n");
        for(int i=0;i<=100;i++){
            gotoxy(0,15);
            printf("\t\t\t ====== Loading--------------------------------------%d ======",i);
            system("cls");
}
    char pilih;
    while(1)
    {
        system("cls");
        printf("\t\t\t Program Administrator Siasat Universitas Kristen Satya Wacana \n\n");
        printf("\t\t\t =======================Pilihan Operasi=======================\n\n");
        printf("\t\t\t 1. Tambah Data Matakuliah\n");
        printf("\t\t\t 2. Lihat Data Matakuliah\n");
        printf("\t\t\t 3. Edit Data Matakuliah\n");
        printf("\t\t\t 4. Hapus Data Matakuliah\n");
        printf("\t\t\t 5. Cari Data Matakuliah\n");
        printf("\t\t\t 6. Histori \n");
        printf("\t\t\t 7. Urutkan Data Matakuliah\n");
        printf("\t\t\t 8. Logout \n");
        printf("\n\t\t\t Pilihan Operasi Yang Akan Anda Lakukan : ");
        scanf("%d",&pilih);


        switch(pilih)
        {
        case 1:
            tambah_data();
            break;
        case 2:
            system("cls");
            printf("\t\t\t Data Penghuni Kos\n\n");
            lihat_data();
            getch();
            break;
        case 3:
            pilih_data("Ubah");
            break;
        case 4:
            system("cls");
            hapus_data();
            break;
        case 5:
            system("cls");
            search();
            break;
        case 6:
            pilih_data("Riwayat");
            break;
        case 7:
            system("cls");
            printf("\t\t\t Urutkan Berdasarkan Kode Matakuliah \n");
            urutkan();
        lihat_data();
            getch();
            break;
        case 8:
        goto login;

        }
    }
    }else
    printf("\n\t\t\t login Gagal! silahkan coba lagi");
    getch();
    goto login;
}




