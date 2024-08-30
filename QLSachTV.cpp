#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

#define MAX 100

typedef struct
{
    char maSach[10];
    char tenSach[30];
    char tenTacGia[30];
    char nhaXuatBan[30];
    int namXuatBan;
    char theLoai[30];
    char kesach[12];
} Sach;

typedef struct Node
{
    Sach data;
    struct Node* next;
} Node;

typedef struct
{
    Node* head;
    Node* tail;
} List;

Node* createNode(Sach data)
{
    Node* p = (Node*)malloc(sizeof(Node));
    if (p == NULL)
    {
        printf("Khong du bo nho de cap phat");
        return NULL;
    }
    p->data = data;
    p->next = NULL;
    return p;
}

void initList(List* list)
{
    list->head = list->tail = NULL;
}

int isEmpty(List list)
{
    return list.head == NULL;
}

// Nhập sách từ bàn phím 
void input(List* list)
{
    Sach data;
    char choice;
    do
    {
        rewind(stdin);
        printf("Nhap ma sach: ");
        fflush(stdin);
        gets(data.maSach);
        printf("Nhap ten sach: ");
        fflush(stdin);
        gets(data.tenSach);
        printf("Nhap ten tac gia: ");
        fflush(stdin);
        gets(data.tenTacGia);
        printf("Nhap nha xuat ban: ");
        fflush(stdin);
        gets(data.nhaXuatBan);
        printf("Nhap nam xuat ban: ");
        scanf("%d", &data.namXuatBan);
        rewind(stdin);
        printf("Nhap the loai: ");
        fflush(stdin);
        gets(data.theLoai);
        printf("Nhap ke sach : ");
        fflush(stdin);
        gets(data.kesach);
        Node* p = createNode(data);
        if (isEmpty(*list))
        {
            list->head = list->tail = p;
        }
        else
        {
            list->tail->next = p;
            list->tail = p;
        }
        printf("Ban co muon nhap tiep (y/n): ");
        fflush(stdin);
        scanf("%c", &choice);
    } while (choice == 'y' || choice == 'Y');
}

void output(List list)
{
    for (Node* data = list.head; data != NULL; data = data->next)
        printf("%5s%30s%25s%25s%10d%20s%10s\n", data->data.maSach, data->data.tenSach, data->data.tenTacGia, data->data.nhaXuatBan, data->data.namXuatBan, data->data.theLoai);
}

//Nhập từ file
void inputToFile(List* l)
{
    Sach x;
    int n;
    char c;
    FILE* f = fopen("Text.txt", "r");
    if (f == NULL)
    {
        printf("\nFile rong!");
        return;
    }
    fscanf(f, "%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        fgets(x.maSach, 10, f);
        x.maSach[strlen(x.maSach) - 1] = NULL;
        fgets(x.tenSach, 30, f);
        x.tenSach[strlen(x.tenSach) - 1] = NULL;
        fgets(x.tenTacGia, 30, f);
        x.tenTacGia[strlen(x.tenTacGia) - 1] = NULL;
        fgets(x.nhaXuatBan, 30, f);
        x.nhaXuatBan[strlen(x.nhaXuatBan) - 1] = NULL;
        fscanf(f, "%d\n", &x.namXuatBan);
        fgets(x.theLoai, 30, f);
        x.theLoai[strlen(x.theLoai) - 1] = NULL;
        Node* p = createNode(x);
        if (isEmpty(*l))
        {
            l->head = l->tail = p;
        }
        else
        {
            p->next = l->head;
            l->head = p;
        }
    }
    fclose(f);
}

//Nhập thông tin sách và thêm vào đầu 
void insertAtHead(List* list)
{
    Sach data;
    printf("\nNhap ma sach: ");
    rewind(stdin);
    gets(data.maSach);
    printf("\nNhap ten sach: ");
    rewind(stdin);
    gets(data.tenSach);
    printf("\nNhap ten tac gia: ");
    rewind(stdin);
    gets(data.tenTacGia);
    printf("\nNhap nha xuat ban: ");
    rewind(stdin);
    gets(data.nhaXuatBan);
    printf("\nNhap nam xuat ban: ");
    scanf("%d", &data.namXuatBan);
    printf("\nNhap the loai: ");
    rewind(stdin);
    gets(data.theLoai);
    Node* p = createNode(data);
    if (isEmpty(*list))
    {
        list->head = list->tail = p;
    }
    else
    {
        p->next = list->head;
        list->head = p;
    }
}

//Nhập thông tin sách và thêm vào cuối
void insertAtTail(List* list)
{
    Sach data;
    printf("\nNhap ma sach: ");
    rewind(stdin);
    gets(data.maSach);
    printf("\nNhap ten sach: ");
    rewind(stdin);
    gets(data.tenSach);
    printf("\nNhap ten tac gia: ");
    rewind(stdin);
    gets(data.tenTacGia);
    printf("\nNhap nha xuat ban: ");
    rewind(stdin);
    gets(data.nhaXuatBan);
    printf("\nNhap nam xuat ban: ");
    scanf("%d", &data.namXuatBan);
    printf("\nNhap the loai: ");
    rewind(stdin);
    gets(data.theLoai);
    Node* p = createNode(data);
    if (isEmpty(*list))
    {
        list->head = list->tail = p;
    }
    else
    {
        list->tail->next = p;
        list->tail = p;
    }
}

//Nhập thông tin sách và chen vào sau sách có mã x
void insertAfter(List* list, char x[])
{
    Sach data;
    rewind(stdin);
    printf("\nNhap ma sach: ");
    rewind(stdin);
    gets(data.maSach);
    printf("\nNhap ten sach: ");
    rewind(stdin);
    gets(data.tenSach);
    printf("\nNhap ten tac gia: ");
    rewind(stdin);
    gets(data.tenTacGia);
    printf("\nNhap nha xuat ban: ");
    rewind(stdin);
    gets(data.nhaXuatBan);
    printf("\nNhap nam xuat ban: ");
    scanf("%d", &data.namXuatBan);
    printf("\nNhap the loai: ");
    rewind(stdin);
    gets(data.theLoai);
    Node* p = createNode(data);
    if (isEmpty(*list))
    {
        list->head = list->tail = p;
    }
    else
    {
        Node* q = list->head;
        while (q != NULL && strcmp(q->data.maSach, x) != 0)
        {
            q = q->next;
        }
        if (q == NULL)
        {
            printf("Khong tim thay sach co ma %s", x);
            return;
        }
        else
        {
            p->next = q->next;
            q->next = p;
        }
    }
}

//Xóa sách ở vị trí đầu 
void deleteAtHead(List* list)
{
    if (isEmpty(*list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list->head;
    list->head = list->head->next;
    free(p);
    printf("Xoa thanh cong\n");
}

//Xóa sách ở vị trí cuối 
void deleteAtTail(List* list)
{
    if (isEmpty(*list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list->head;
    while (p->next != list->tail)
    {
        p = p->next;
    }
    p->next = NULL;
    free(list->tail);
    list->tail = p;
    printf("Xoa thanh cong\n");
}

Node* CreateNode(Sach x)
{
    Node* p = new Node;
    if (p == NULL)
    {
        printf("\nKhong du bo nho cap phat!");
        return NULL;
    }
    else
    {
        p->data = x;
        p->next = NULL;
    }
    return p;
}

// Xóa sách có mă sách là x
void deleteAfter(List* list, char x[])
{
    if (isEmpty(*list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list->head;
    while (p != NULL && strcmp(p->data.maSach, x) != 0)
    {
        p = p->next;
    }
    if (p == NULL)
    {
        printf("Khong tim thay sach co ma %s", x);
        return;
    }
    else
    {
        Node* q = list->head;
        while (q->next != p)
        {
            q = q->next;
        }
        q->next = p->next;
        free(p);
        printf("Xoa thanh cong\n");
    }
}

//Sắp xếp theo thể loại
void sortByTheLoai(List& list)
{
    if (isEmpty(list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list.head;
    while (p != NULL)
    {
        Node* q = p->next;
        while (q != NULL)
        {
            if (strcmp(p->data.theLoai, q->data.theLoai) > 0)
            {
                Sach temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            if (strcmp(p->data.theLoai, q->data.theLoai) == 0)
            {
                if (strcmp(p->data.maSach, q->data.maSach) > 0)
                {
                    Sach t = p->data;
                    p->data = q->data;
                    q->data = t;
                }
            }
            q = q->next;
        }
        p = p->next;
    }
}

//Thêm 1 sách vào danh sách và sắp xếp lại danh sách thể loại
void insertAndSort(List* list)
{
    Sach data;
    rewind(stdin);
    printf("\nNhap ma sach: ");
    rewind(stdin);
    gets(data.maSach);
    printf("\nNhap ten sach: ");
    rewind(stdin);
    gets(data.tenSach);
    printf("\nNhap ten tac gia: ");
    rewind(stdin);
    gets(data.tenTacGia);
    printf("\nNhap nha xuat ban: ");
    rewind(stdin);
    gets(data.nhaXuatBan);
    printf("\nNhap nam xuat ban: ");
    scanf("%d", &data.namXuatBan);
    printf("\nNhap the loai: ");
    rewind(stdin);
    gets(data.theLoai);
    Node* p = createNode(data);
    if (isEmpty(*list))
    {
        list->head = list->tail = p;
    }
    else
    {
        Node* q = list->head;
        while (q != NULL && strcmp(q->data.theLoai, data.theLoai) < 0)
        {
            q = q->next;
        }
        if (q == NULL)
        {
            list->tail->next = p;
            list->tail = p;
        }
        else
        {
            if (q == list->head)
            {
                p->next = list->head;
                list->head = p;
            }
            else
            {
                Node* r = list->head;
                while (r->next != q)
                {
                    r = r->next;
                }
                r->next = p;
                p->next = q;
            }
        }
    }
    printf("\nDanh sach sau khi them va sap xep:\n");
    output(*list);
}

// Thống kê số sách của trong từng NXB của mỗi tác giả.Ví dụ : Hoàng Kiếm có 4 sách ở NXB Tuổi trẻ, 3 cuốn ở NXB Bộ GDĐT, 1 quyển ở NXB ĐHQG.
void thongKe(List list)
{
    if (isEmpty(list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list.head;
    while (p != NULL)
    {
        int count = 0;
        Node* q = list.head;
        while (q != NULL)
        {
            if (strcmp(p->data.tenTacGia, q->data.tenTacGia) == 0 && strcmp(p->data.nhaXuatBan, q->data.nhaXuatBan) == 0)
            {
                count++;
            }
            q = q->next;
        }
        printf("\n%s co %d quyen sach o %s \n", p->data.tenTacGia, count, p->data.nhaXuatBan);
        p = p->next;
    }
}

//Tìm nhà xuất bản có ít sách nhất
void findNXB(List list) // C
{
    if (isEmpty(list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list.head;
    int min = 1000;
    while (p != NULL)
    {
        int count = 0;
        Node* q = list.head;
        while (q != NULL)
        {
            if (strcmp(p->data.nhaXuatBan, q->data.nhaXuatBan) == 0)
            {
                count++;
            }
            q = q->next;
        }
        if (count < min)
        {
            min = count;
        }
        p = p->next;
    }
    printf("\nNha xuat ban co it sach nhat la: \n");
    p = list.head;
    while (p != NULL)
    {
        int count = 0;
        Node* q = list.head;
        while (q != NULL)
        {
            if (strcmp(p->data.nhaXuatBan, q->data.nhaXuatBan) == 0)
            {
                count++;
            }
            q = q->next;
        }
        if (count == min)
        {
            printf("%s\n ", p->data.nhaXuatBan);
        }
        p = p->next;
    }
}

//Thông kê sách theo từng năm xuất bản của từng NXB
void thongKeTheoNam(List list)
{
    if (isEmpty(list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list.head;
    while (p != NULL)
    {
        Node* q = p->next;
        while (q != NULL)
        {
            if ((p->data.namXuatBan >= q->data.namXuatBan))
            {
                Sach temp = p->data;
                p->data = q->data;
                q->data = temp;
            }
            q = q->next;
        }
        p = p->next;
    }
    output(list);
}

//Đếm số lượng sách theo từng thể loại
void demTheLoai(List list)
{
    if (isEmpty(list))
    {
        printf("Danh sach rong");
        return;
    }
    sortByTheLoai(list);
    int count = 1;
    Node* q = list.head;
    while (q != NULL)
    {
        if (q->next == NULL) { printf("\n%s co %d quyen sach", q->data.theLoai, count);  break; }
        Node* p = q->next;
        if (strcmp(q->data.theLoai, p->data.theLoai) == 0)
        {

            count++;
        }
        else
        {
            printf("\n%s co %d quyen sach", q->data.theLoai, count);
            count = 1;

        }
        q = q->next;
    }
}

// Có bao nhiêu sách mà tên có chứa chuỗi lập trình” do NXB ĐHQG và NXB KHKT xuất bản? xuất thông tin các sách đó.
void findSach(List list)
{
    if (isEmpty(list))
    {
        printf("Danh sach rong");
        return;
    }
    Node* p = list.head;
    while (p != NULL)
    {
        if (strcmp(p->data.nhaXuatBan, "NXB DHQG") == 0 || strcmp(p->data.nhaXuatBan, "NXB KHKT") == 0)
        {
            if (strstr(p->data.tenSach, "Lap Trinh") != NULL)
            {
                printf("\n%s", p->data.tenSach);
            }
        }
        p = p->next;
    }
}

int main()
{
    List list;
    initList(&list);
    // Tạo menu
    int choice;
    system("color B");
    do
    {
        printf("\n---------------------------------------------------------------\n");
        printf("|                   QUAN LI SACH TRONG THU VIEN               |");
        printf("\n---------------------------------------------------------------\n");
        printf("1. Nhap thong tin sach tu file\n");
        printf("2. Nhap thong tin sach\n");
        printf("3. Xuat thong tin sach\n");
        printf("4. Them sach vao danh sach\n");
        printf("5. Them sach vao cuoi danh sach\n");
        printf("6. Them sach vao sau sach co ten la ...\n");
        printf("7. Xoa sach dau danh sach\n");
        printf("8. Xoa sach cuoi danh sach\n");
        printf("9. Xoa sach co ten la ...\n");
        printf("10. Sap xep sach theo the loai\n");
        printf("11. Them 1 sach vao dau danh sach sao cho van dam bao sap xep\n");
        printf("12. Thong ke so sach cua trong tung NXB cua moi tac gia\n");
        printf("13. Tim nha xuat ban co it sach nhat\n");
        printf("14. Thong ke sach theo nam xuat ban cua tung NXB\n");
        printf("15. Dem so luong sach theo tung the loai\n");
        printf("16. Tim sach co ten chua chuoi lap trinh do NXB DHQG va NXB KHKT xuat ban\n");
        printf("0. Thoat\n");
        printf("\n--------------------------------------------------------------\n");
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        {
            inputToFile(&list);
            break;
        }
        case 2:
        {
            input(&list);
            break;
        }
        case 3:
            system("cls");
            output(list);
            break;
        case 4:
            system("cls");
            insertAtHead(&list);
            break;
        case 5:
            system("cls");
            insertAtTail(&list);
            break;
        case 6:
        {
            system("cls");
            char x[50];
            rewind(stdin);
            printf("\nNhap ma sach can them vao sau: ");
            fflush(stdin);
            gets(x);
            insertAfter(&list, x);
            break;
        }
        case 7:
            system("cls");
            deleteAtHead(&list);
            break;
        case 8:
            system("cls");
            deleteAtTail(&list);
            break;
        case 9:
        {
            system("cls");
            char y[50];
            rewind(stdin);
            printf("\nNhap ma sach can xoa: ");
            fflush(stdin);
            gets(y);
            deleteAfter(&list, y);
            break;
        }
        case 10:
            system("cls");
            sortByTheLoai(list);
            output(list);
            break;
        case 11:
            system("cls");
            insertAndSort(&list);
            break;
        case 12:
            system("cls");
            thongKe(list);
            break;
        case 13:
            system("cls");
            findNXB(list);
            break;
        case 14:
            system("cls");
            thongKeTheoNam(list);
            break;
        case 15:
            system("cls");
            demTheLoai(list);
            break;
        case 16:
            system("cls");
            findSach(list);
            break;
        case 0:
            printf("Da thoat chuong trinh\n");
            break;
        default:
            printf("Nhap sai, nhap lai\n");
            break;
        }
    } while (choice != 0);
    return 0;
}
