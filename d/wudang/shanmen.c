//Cracked by Roath
// shanmen.c �䵱������
// by Xiang

inherit ROOM;
#include <ansi.h>;
int do_exercise(string);

void create()
{
	set("short", "������");
	set("long", @LONG
�����ǰ��һ����ľ��ï�ĸ�ɽ������ɽ������������Լ�ɼ���һ��ʯ
����ɽ�����죬���ż�������͡�һ����¥ʽ��ʯ����ɽ������д�š�����
�š��������֣�ԭ������������������䵱ɽ���䵱ɽһ��̫��ɽ��Ϊ��ʮ
������֮һ���ж�ʮ�߷塢��ʮ���ҡ���ʮ�Ľ�����̨���微����̶������
�š��������һ���أ�����������ɭ�ޣ����ղ��죬�����ľ���
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"east" : __DIR__"pine_road",
		"southup" : __DIR__"shijie1",
	]));
        set("objects", ([
                CLASS_D("wudang")+"/zhike" : 1]));
	set("cost", 3);
	setup();
//	replace_program(ROOM);
}

void init()
{
	add_action("do_exercise", "exercise");
	add_action("do_exercise", "dazuo");
	add_action("do_exercise", "respirate");
	add_action("do_exercise", "tuna");
	add_action("do_exercise", "lian");
	add_action("do_exercise", "practice");
	add_action("do_exercise", "study");
	add_action("do_exercise", "du");
	add_action("do_exercise", "sleep");
}

int do_exercise(string arg)
{
	object me = this_player();

	if ( me->query("job/description") == "����ɽ��" || me->query("job/guarding") > 0 )
	{
		tell_object(me, "�㻹��ר�����Űɣ�\n");
		return 1;
	}
	
	return 0;
}


int valid_leave(object me, string dir)
{
	mapping myfam;
	object wp, *inv;
	int i, j=0;

	myfam = (mapping)me->query("family");

	if ( (string)me->query("job/allow") > 0)
		return me->delete("job/allow");
			
				
	
	if ( (string)me->query("job/description") == "����ɽ��" )
	if (objectp(present("zhike daozhang", environment(me))))
		return notify_fail("֪�͵����ȵ���ʱ��δ����������\n");
	else 		
	{
		message_vision("$N��֪�͵������ڣ��û������ˡ�\n", me); 	

		me->delete("job/guarding");
		me->delete("job/allow");
		me->delete_temp("apply/short");
		me->add("job/fail", 1);
		me->delete("job/supervisor");
		me->delete("job/description");
		me->delete("job/wage");
		me->delete("job/object");
	}
	

	if ( dir == "southup" && (me->query("shen") < -99)
		&& !objectp(present("incense", me)) )
	{
        inv = all_inventory(this_object());
    
        for (i = 0; i < sizeof(inv); i++)
        if (userp(inv[i]) && (string)inv[i]->query("job/description") == "����ɽ��")
		{
			j++;
			if (objectp(wp = inv[i]->query_temp("weapon")))
				message_vision("$N��$n�ȵ�������аħ������Ҫ�����ɽ�ţ��������������е�"
				+ wp->query("name")+ "��Ӧ����Ӧ��\n", inv[i], me); 
			else 
				message_vision("$N��$n�ȵ���ֻҪ���ڣ�����аħ���������������ɽ�ţ�\n", inv[i], me);
		}

        if ( objectp(present("zhike daozhang", environment(me))) )
            return notify_fail("֪�͵����γ����������㣺�粻����ɽ���㣬������أ�\n");
            
        if (j) return notify_fail("\n");    
	}
	
	return 
		
		::valid_leave(me, dir);
		
}

void reset() 
{
        int i;
        mapping worker = query_temp("worker");
        string* players;

        if ( mapp(worker) && sizeof(worker) ) {
                players = keys(worker);
                for(i=0; i<sizeof(players); i++) 
                        if (query_temp("worker/"+players[i])>0)
                                add_temp("worker/"+players[i], -1);
        }

	return ::reset();
}
