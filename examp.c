#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*! fitur delete bisa memilih simpul yang akan dihapus berdasarkan id.
 Jadi jika saya memiliki 2 data dan saya ingin menghapus data ke-2, maka simpul akan mengarah ke
 simpul berikutnya (simpul->next), yang artinya simpul berikutnya ini berisi NULL karna saya tidak memiliki simpul lain / simpul ke-3. Jadi di sini problemnya, ketika saya ingin menampilkan semua data, saya tidak bisa menampilkan data ke-1 karena simpul langsung mengarah ke simpul->next, data tersebut tidak ada. dan hasilnya "Queue is empty".
*/

typedef struct queue
{
    char nama[80];
    char alamat[80];
    char email[80];
    int NIM, id;
    struct queue *next;
} queue;

int insert(queue **front, queue **rear, char nama[80], char alamat[80], char email[80], int NIM)
{
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    strcpy(temp->nama, nama);
    strcpy(temp->alamat, alamat);
    strcpy(temp->email, email);
    temp->NIM = NIM;
    temp->id = 1;
    temp->next = NULL;
    if (*front == NULL)
    {
        *front = temp;
    }
    else
    {
        temp->id = (*rear)->id + 1;
        (*rear)->next = temp;
        *rear = temp;
    }
    *rear = temp;
    return 0;
}

int delete (queue **front, queue **rear, char nama[80], char alamat[80], char email[80], int NIM)
{
    queue *temp;
    int selected_id;
    if (*front != NULL)
    {
        printf("hapus berdasarkan id: ");
        scanf("%d", &selected_id);

        while (*front != NULL)
        {
            if ((*front)->id == selected_id)
            {
                temp = *front;           // ambil element paling atas
                *front = (*front)->next; //! line yang menjadi problem
                strcpy(nama, temp->nama);
                strcpy(alamat, temp->alamat);
                strcpy(email, temp->email);

                printf("%s has deleted\n", nama);
                printf("%d has deleted\n", NIM);
                printf("%s has deleted\n", alamat);
                printf("%s has deleted\n", email);
                free(temp);
                return 1;
            }
            else
            {
                *front = (*front)->next;
            }
        }
    }
    else
    {
        printf("Queue is Empty\n");
        return 0;
    }
    return 1;
}

int display(queue *front)
{
    char value[80] = {};
    queue *temp;
    int i;
    temp = front;
    if (temp == NULL)
    {
        printf("Queue is Empty\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("(%d) - ", temp->id);
            printf("%s_", temp->nama);
            printf("%d_", temp->NIM);
            printf("%s_", temp->alamat);
            printf("%s", temp->email);
            temp = temp->next;
            printf("\n");
        }
    }
    return 0;
}

// int modify(queue **front, queue **rear, char nama[80], char alamat[80], char email[80], int NIM)
// {
//     queue *temp;
//     int select;
//     temp = *front;
//     if (temp == NULL)
//     {
//         printf("Queue is Empty\n");
//     }
//     else
//     {
//         printf("Select the data you want to modify by id: ");
//         scanf("%d", &select);
//         while (temp != NULL)
//         {
//             if (temp->id == select)
//             {
//                 printf("enter %s: ", temp->nama);
//                 scanf("%s", temp->nama);
//                 printf("enter %s: ", temp->alamat);
//                 scanf("%s", temp->alamat);
//                 printf("enter %s: ", temp->email);
//                 scanf("%s", temp->email);
//                 printf("enter %d: ", temp->NIM);
//                 scanf("%d", &temp->NIM);
//                 printf("%s has modified\n", temp->nama);
//                 printf("%s has modified\n", temp->alamat);
//                 printf("%s has modified\n", temp->email);
//                 printf("%d has modified\n", temp->NIM);
//                 return 1;
//             }
//             temp = temp->next;
//         }
//     }
//     return 0;
// }

int main()
{
    queue *front = NULL;
    queue *rear = NULL;
    char nama[80], alamat[80], email[80];
    int NIM, id;
    int choice;
    do
    {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        // printf("4. Modify data by id\n");
        printf("5. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n!program ga bisa detect spasi, jangan dimasukkin \n");
            printf("Masukkan Nama: ");
            scanf("%s", nama);
            printf("Masukkan NIM: ");
            scanf("%d", &NIM);
            printf("Masukkan Alamat: ");
            scanf("%s", alamat);
            printf("Masukkan Email: ");
            scanf("%s", email);
            insert(&front, &rear, nama, alamat, email, NIM);
            break;
        case 2:
            delete (&front, &rear, nama, alamat, email, NIM);
            break;
        case 3:
            display(front);
            break;
        // case 4:
        //     modify(&front, &rear, nama, alamat, email, NIM);
        //     break;
        case 5:
            break;
        default:
            printf("Invalid choice\n");
        }
    } while (choice != 5);
    return 0;
}

// ori program muhammad erlangga 21107004