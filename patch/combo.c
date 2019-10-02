static int combo = 0;

void
keyrelease(XEvent *e)
{
	combo = 0;
}

void
combotag(const Arg *arg)
{
	if (selmon->sel && arg->ui & TAGMASK) {
		if (combo) {
			selmon->sel->tags |= arg->ui & TAGMASK;
		} else {
			combo = 1;
			selmon->sel->tags = arg->ui & TAGMASK;
		}
		focus(NULL);
		arrange(selmon);
	}
}

void
comboview(const Arg *arg)
{
	unsigned newtags = arg->ui & TAGMASK;
	if (combo) {
		selmon->tagset[selmon->seltags] |= newtags;
	} else {
		selmon->seltags ^= 1;	/*toggle tagset*/
		combo = 1;
		if (newtags) {
			#if PERTAG_PATCH
			pertagview(&((Arg) { .ui = newtags }));
			#else
			selmon->tagset[selmon->seltags] = newtags;
			#endif // PERTAG_PATCH
		}
	}
	focus(NULL);
	arrange(selmon);
}