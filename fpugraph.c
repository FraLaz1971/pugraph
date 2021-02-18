#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <plot.h>

/* global variables */

char tl[64] ;   /* title above the plot */
char au[64] ;   /* author signature */

int c_x, c_y;
int ret;

void draw_test_circles(plPlotter *plotter)
{
    sprintf(tl,  "Awesome Circles");
    sprintf(au,  "by FraLaz1971");
    c_x = 100; c_y = 100;
    
    pl_fspace_r (plotter, 0.0, 0.0, 400.0, 400.0); /* set coord. system */
    pl_flinewidth_r (plotter, 0.25);    /* set line thickness */
    pl_erase_r (plotter);    /* erase graphics display */

    pl_fmove_r(plotter, 100.0, 200.0); /* position the graphics cursor at point 100,200*/
    pl_pencolorname_r (plotter, "black"); /* use black pen */
    pl_alabel_r(plotter, 10, 10, tl); /* plot the title */
    
    pl_fmove_r (plotter, 100.0, 190.0); /* position the graphics cursor */
    pl_fcont_r (plotter, 160.0, 190.0); /* plot a line until point 160,190 */
    
    pl_fmove_r(plotter, 100.0, 100.0); /* position the graphics cursor */
    pl_circle_r(plotter, c_x, c_y, 50); /* plot a circle of radius 50 centered in 100,100 */

    pl_pencolorname_r(plotter, "red"); /* use red pen */
    pl_circle_r(plotter, c_x, c_y, 75); /* plot a circle of radius 75 centered in 100,100 */

    pl_pencolorname_r(plotter, "green"); /* use green pen */
    pl_circle_r(plotter, c_x, c_y, 100); /* plot a circle of radius 100 centered in 100,100 */

    pl_fmove_r(plotter, 10.0, 10.0); /* position the graphics cursor to point 10,10 */
    pl_pencolorname_r (plotter, "blue"); /* use blue pen */
    pl_alabel_r(plotter, 10, 10, au); /* plot the author name */
    
}

int main (int argc, char **argv)
{
    plPlotter *plotter;
    plPlotterParams *plotter_params;
    /* set a Plotter parameter */
    plotter_params = pl_newplparams ();
    pl_setplparam (plotter_params, "PAGESIZE", "A4");
    /* create a Postscript Plotter that writes to standard output */
    if ((plotter = pl_newpl_r ("ps", stdin, stdout, stderr,
    plotter_params)) == NULL)
    {
    fprintf (stderr, "%s: Couldn’t create Plotter\n", argv[0]);
        return 1;
    }
    if (pl_openpl_r (plotter) < 0)
    /* open Plotter */
    {
        fprintf (stderr, "%s: Couldn’t open Plotter\n", argv[0]);
        return 1;
    }
    pl_fspace_r (plotter, 0.0, 0.0, 1000.0, 1000.0); /* set coord. system */
    pl_flinewidth_r (plotter, 0.25);    /* set line thickness */
    pl_erase_r (plotter);    /* erase graphics display */
    draw_test_circles(plotter);

    if (pl_closepl_r (plotter) < 0)    /* close Plotter */
    {
        fprintf (stderr, "%s: Couldn’t close Plotter\n", argv[0]);
        return 1;
    }
    if (pl_deletepl_r (plotter) < 0)
    /* delete Plotter */
    {
        fprintf (stderr, "%s: Couldn’t delete Plotter\n", argv[0]);
        return 1;
    }
    return 0;
}
