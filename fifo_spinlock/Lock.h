#pragma once
#include <windows.h>
//���ܣ�ʵ��FIFIO�����ĵ�������
//ʵ��˼·��
//�ڿͻ��߳����һ����ǣ����ֳ���ͼȥlockʱ�����û��ռ�óɹ�������Լ���ticket,����ռ�Ĵ���
//�����������ݽṹ������¼��һ������ʹ�õ��̣߳�Ҳ����˵���ݽṹ���汣������һ����ռ�̵߳�ticket
//ֻ������߳�����ռʱ�Ż�ɹ�

//code by fxp


class SpinLock
{
public:
	SpinLock()
	{
		m_status = 0;
		m_cur_ticket = 0;
		m_next_ticket = 0;
		m_tickets = 0;
	}

	~SpinLock()
	{}

public:

	bool try_lock(long ticket)
	{
		if (ticket != m_next_ticket) return false;
		long l = InterlockedExchangeAdd((long*)(&m_status), 1);
		return l == 0;
	}

	void lock()
	{
		long old_ticket = InterlockedExchangeAdd((long*)(&m_tickets), 1);
		for (unsigned u = 0; !try_lock(old_ticket); ++u);
	}

	void unlock()
	{
		long old_ticket = InterlockedExchangeAdd((long*)(&m_next_ticket), 1);
		m_status = 0;
	}

private:
	volatile long m_status;
	volatile long m_cur_ticket;
	volatile long m_next_ticket;
	volatile long m_tickets;
};
