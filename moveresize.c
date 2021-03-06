void
moveresize(const Arg *arg) {
	XEvent ev;
	Monitor *m = selmon;

	if (!(m->sel && arg && arg->v && m->sel->isfloating))
		return;

	resize(m->sel, m->sel->x + ((int *)arg->v)[0],
		m->sel->y + ((int *)arg->v)[1],
		m->sel->w + ((int *)arg->v)[2],
		m->sel->h + ((int *)arg->v)[3],
		1);

	while (XCheckMaskEvent(dpy, EnterWindowMask, &ev));
}
