#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "07_3. ť_BankQueue.h"

//�ùķ��̼ǿ� �ʿ��� �������� ���� ����
int duration = 10; //�ùķ��̼� �ð�
double arrival_prob = 0.7; //�ϳ��� �ð� ������ �����ϴ� ��� ������ ��
int max_serv_time = 5; //�ϳ��� ���� ���� �ִ� ���� �ð�
int clock;

//�ùķ��̼��� ���
int customers; //��ü ����
int served_customers; //���񽺹��� ����
int waited_time; //������ ��ٸ� �ð�

double random() {
	printf("%f\n", (double)rand());
	printf("%f\n", (double)RAND_MAX);
	return rand() / (double)RAND_MAX;
}

//���� ���ڸ� �����Ͽ� ���� �����ߴ��� �������� �ʾҴ����� �Ǵ�
int is_customer_arrived() {
	if (random() < arrival_prob)
		return TRUE;
	else return FALSE;
}

//���� ������ ���� ť�� ����
void insert_customer(int arrival_time) {
	element customer;

	customer.id = customers++;
	customer.arrival_time = arrival_time;
	customer.service_time = (int)(max_serv_time * random()) + 1;
	enqueue(&queue, customer);
	printf("�� %d�� %d�п� ���ɴϴ�. ���� �ð��� %d���Դϴ�.\n", customer.id, customer.arrival_time, customer.service_time);
}

//ť���� ��ٸ��� ���� ������ ���� ���� �ð��� ��ȯ
int remove_customer() {
	element customer;
	int service_time = 0;

	if (is_empty(&queue))return 0;
	customer = dequeue(&queue);
	service_time = customer.service_time - 1;
	served_customers++;
	waited_time += clock - customer.arrival_time;
	printf("�� %d�� %d�п� ���񽺸� �����մϴ�. ���ð��� %d���̾����ϴ�.\n", customer.id, clock, clock - customer.arrival_time);
	return service_time;
}

//���ġ�� ���
void print_stat() {
	printf("\n\n���񽺹��� ����= %d\n", served_customers);
	printf("��ü ��� �ð�= %d\n", waited_time);
	printf("1�δ� ��� ��� �ð�=%f��\n", (double)waited_time / served_customers);
	printf("���� ������� ����=%d\n\n", customers - served_customers);
}

void main() {
	int service_time = 0;

	clock = 0;
	while (clock < duration) {
		clock++;
		printf("\n����ð�= %d\n", clock);
		if (is_customer_arrived()) {
			insert_customer(clock);
		}
		if (service_time > 0)
			service_time--;
		else {
			service_time = remove_customer();
		}
	}
	print_stat();
}