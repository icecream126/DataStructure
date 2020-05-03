#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int num = 9;
int heap[9] = { 3,7,8,9,2,4,1,6,5 };
int main() {
	for (int i = 1; i < num; i++) {
		int cur = i;
		do {
			int root = (cur - 1) / 2;
			//�θ��尡 ������ ��ȯ
			if (heap[root] < heap[cur]) {
				int tmp = heap[root];
				heap[root] = heap[cur];
				heap[cur] = tmp;
			}
			//���� ��带 �ٽ� ��Ʈ�� �ٲ�
			cur = root;
		} while (cur != 0);
	}
	//9 8 7 6 2 4 1 3 5
	for (int i = num - 1; i >= 0; i--) {
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		int root = 0;
		int cur = 1;
		do {
			cur = 2 * root + 1;
			//�ڽ� ��� �� ū �ڽ� ã��
			//������ �ڽ� ��尡 �� ū ��� ������ �ڽ����� �̵�
			if (cur < i - 1 && heap[cur] < heap[cur + 1]) {
				cur++;
			}
			if (cur < i && heap[root] < heap[cur]) {
				tmp = heap[root];
				heap[root] = heap[cur];
				heap[cur] = tmp;
			}
			root = cur;
		} while (cur < i);
	}
	for (int i = 0; i < num; i++) {
		printf("%d ", heap[i]);
	}
}