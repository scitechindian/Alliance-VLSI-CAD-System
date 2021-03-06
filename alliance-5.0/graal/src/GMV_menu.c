/*------------------------------------------------------------\
|                                                             |
| This file is part of the Alliance CAD System Copyright      |
| (C) Laboratoire LIP6 - Département ASIM Universite P&M Curie|
|                                                             |
| Home page      : http://www-asim.lip6.fr/alliance/          |
| E-mail         : mailto:alliance-users@asim.lip6.fr       |
|                                                             |
| This progam is  free software; you can redistribute it      |
| and/or modify it under the  terms of the GNU General Public |
| License as  published by the Free Software Foundation;      |
| either version 2 of the License, or (at your option) any    |
| later version.                                              |
|                                                             |
| Alliance VLSI  CAD System  is distributed  in the hope that |
| it  will be useful, but WITHOUT  ANY WARRANTY;              |
| without even the  implied warranty of MERCHANTABILITY or    |
| FITNESS FOR A PARTICULAR PURPOSE. See the GNU General       |
| Public License for more details.                            |
|                                                             |
| You should have received a copy  of the GNU General Public  |
| License along with the GNU C Library; see the file COPYING. |
| If not, write to the Free Software Foundation, Inc.,        |
| 675 Mass Ave, Cambridge, MA 02139, USA.                     |
|                                                             |
\------------------------------------------------------------*/

/*------------------------------------------------------------\
|                                                             |
| Tool    :                   GRAAL                           |
|                                                             |
| File    :                   Menu.c                          |
|                                                             |
| Author  :                Jacomme Ludovic                    |
|                                                             |
| Date    :                  28.03.95                         |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                         Include Files                       |
|                                                             |
\------------------------------------------------------------*/

# include <stdio.h>
# include <Xm/Xm.h>
# include <Xm/PushBG.h>
# include <Xm/CascadeBG.h>

# include "mut.h"
# include "mph.h"
# include "rds.h"
# include "rpr.h"
# include "GTB.h"
# include "GSB.h"
# include "GMX.h"
# include "GMV.h"

# include "GMV_menu.h"
# include "GMV_dialog.h"
# include "GMV_view.h"
# include "GMV_map.h"

/*------------------------------------------------------------\
|                                                             |
|                           Constants                         |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                            Types                            |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                          Variables                          |
|                                                             |
\------------------------------------------------------------*/

  char GraalFirstViewLayer = 1;

/*------------------------------------------------------------\
|                                                             |
|                            Menu                             |
|                                                             |
\------------------------------------------------------------*/

   GraalMenuItem GraalViewMenu[] =

         {
           {
             "Zoom",
             'Z',
             "Meta<Key>Z",
             "Meta Z",
             &xmPushButtonGadgetClass,
             False,
             False,
             False,
             CallbackViewZoom,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             (GraalMenuItem *)NULL
           }
           ,
           {
             "Layers",
             'L',
             "Meta<Key>L",
             "Meta L",
             &xmPushButtonGadgetClass,
             False,
             False,
             False,
             CallbackViewLayers,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             (GraalMenuItem *)NULL
           }
           ,
           {
             "Map",
             'M',
             "Meta<Key>P",
             "Meta P",
             &xmPushButtonGadgetClass,
             False,
             False,
             False,
             CallbackViewMap,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             (GraalMenuItem *)NULL
           }
           ,
           {
             "Arrows",
             'A',
             "Meta<Key>A",
             "Meta A",
             &xmPushButtonGadgetClass,
             False,
             False,
             False,
             CallbackViewArrows,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             (GraalMenuItem *)NULL
           }
           ,
           {
             "Grid     ",
             'G',
             "Meta<Key>G",
             "Meta G",
             &xmPushButtonGadgetClass,
             False,
             False,
             False,
             CallbackViewGrid,
             (XtPointer)NULL,
             (Widget)NULL,
             (Widget)NULL,
             (GraalMenuItem *)NULL
           }
           ,
           NULL
         };

/*------------------------------------------------------------\
|                                                             |
|                          Functions                          |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      Callback For Menu                      |
|                                                             |
\------------------------------------------------------------*/
/*------------------------------------------------------------\
|                                                             |
|                      CallbackViewLayers                     |
|                                                             |
\------------------------------------------------------------*/

void CallbackViewLayers( MyWidget, ClientData, CallData )

     Widget  MyWidget;
     caddr_t ClientData;
     caddr_t CallData;
{
  rdsbegin();

  if ( GraalFirstViewLayer )
  {
    GraalInitializeLayer();

    GraalFirstViewLayer = 0;
  }

  GraalEnterPanel( &GraalViewLayerPanel );

  rdsend();
}

/*------------------------------------------------------------\
|                                                             |
|                      CallbackViewGrid                       |
|                                                             |
\------------------------------------------------------------*/

void CallbackViewGrid( MyWidget, ClientData, CallData )

     Widget  MyWidget;
     caddr_t ClientData;
     caddr_t CallData;
{
  rdsbegin();

  GraalEnterPanel( &GraalViewGridPanel );

  rdsend();
}

/*------------------------------------------------------------\
|                                                             |
|                     CallbackViewArrows                      |
|                                                             |
\------------------------------------------------------------*/

void CallbackViewArrows( MyWidget, ClientData, CallData )

     Widget  MyWidget;
     caddr_t ClientData;
     caddr_t CallData;
{
  rdsbegin();

  GraalEnterPanel( &GraalViewArrowsPanel );

  rdsend();
}

/*------------------------------------------------------------\
|                                                             |
|                     CallbackViewZoom                        |
|                                                             |
\------------------------------------------------------------*/

void CallbackViewZoom( MyWidget, ClientData, CallData )

     Widget  MyWidget;
     caddr_t ClientData;
     caddr_t CallData;
{
  rdsbegin();

  GraalEnterPanel( &GraalViewZoomPanel );

  rdsend();
}

/*------------------------------------------------------------\
|                                                             |
|                       CallbackViewMap                       |
|                                                             |
\------------------------------------------------------------*/

void CallbackViewMap( MyWidget, ClientData, CallData )

     Widget  MyWidget;
     caddr_t ClientData;
     caddr_t CallData;
{
  rdsbegin();

  GraalEnterMapPanel();

  rdsend();
}
