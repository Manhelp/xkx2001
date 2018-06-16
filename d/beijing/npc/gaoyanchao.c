//Cracked by Roath
// Npc: 
// Date: 
// kane, 28/9/97

inherit NPC;

void create()
{
	set_name("高彦超", ({
		"gao yanchao",
		"yanchao",
		"gao",
	}));
	set("title", "青木堂会众");
	set("long",
		"他年纪不大，看起来英气勃勃，精明干练。\n"
	);


	set("gender", "男性");
	set("attitude", "heroism");

	set("age", 30);
	set("shen_type",1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_qi", 800);
	set("max_jing", 800);
	set("neili", 600);
	set("max_neili", 600);
	set("combat_exp", 100000);
	set("score", 10);
	

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("cuff", 70);
	set_skill("claw",40);
	set_skill("strike",70);
	set_skill("unarmed",70);
	set_skill("parry", 70);
	set_skill("blade",70);
	set_skill("sword",70);
	set_skill("stick",70);
	set_skill("staff",80);
	
/*
	map_skill("force", "hunyuan-yiqi");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("parry", "luohan-quan");
	map_skill("blade", "cibei-dao");
*/
	setup();

      carry_object("/d/taihu/obj/cloth")->wear();
	carry_object("/d/city/obj/gangdao")->wield();
}

