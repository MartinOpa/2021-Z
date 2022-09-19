#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int to_1d( const int row, const int col, const int cols ) {
    return col + row * cols;
}

typedef unsigned char byte;

typedef struct TGAImage_ TGAImage;

struct TGAImage_ {
    byte id_length;
    byte color_map_type;
    byte image_type;
    byte color_map[5];
    byte x_origin[2];
    byte y_origin[2];
    byte width[2];
    byte height[2];
    byte depth;
    byte descriptor;
};

int tgaimage_width( const TGAImage * self ) {
    int width = 0;

    memcpy( &width, self->width, 2 );

    return width;
}

int tgaimage_height( const TGAImage * self ) {
    int height = 0;

    memcpy( &height, self->height, 2 );

    return height;

}

int tgaimage_channels( const TGAImage * self ) {
    return self->depth / 8;
}
typedef struct TGA_ TGA;

struct TGA_ {
    TGAImage image;
    byte * data;
};


TGA * tga_new( const int width, const int height, const int init_brightness ) {
    TGA * tga = (TGA *)malloc( sizeof( TGA) );

    memset( &tga->image, 0, sizeof( TGAImage ) );

    tga->image.image_type = 3;
    tga->image.depth = 8;
    tga->image.descriptor = 1 << 5;

    memcpy( &tga->image.width, &width, 2 );
    memcpy( &tga->image.height, &height, 2 );

    tga->data = (byte *)malloc( width * height * sizeof( byte ) );
    memset( tga->data, init_brightness, width * height * sizeof( byte ) );

    return tga;
}

void tga_free( TGA ** self ) {
    free( (*self)->data );
    (*self)->data = NULL;
    free( (*self) );
    *self = NULL;
}

int tga_width( const TGA * self ) {
    return tgaimage_width( &self->image );
}

int tga_height( const TGA * self ) {
    return tgaimage_height( &self->image );
}

int tga_channels( const TGA * self ) {
    return tgaimage_channels( &self->image );
}

void tga_set_pixel( TGA * self, const int x, const int y, const byte b ) {
    self->data[ to_1d( y, x, tga_width( self ) ) ] = b;
}

void tga_write( const TGA * self, const char * filename ) {
    FILE * f = fopen( filename, "wb" );
    assert( f );

    fwrite( &self->image, sizeof( TGAImage ), 1, f );

    int res = fwrite( self->data, sizeof( byte ), tga_width( self ) * tga_height( self ) * tga_channels( self ), f );
    assert( res == tga_width( self ) * tga_height( self ) * tga_channels( self ) );

    fclose( f );
}

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} Rect;

void draw_rect( TGA * tga, const Rect * r ) {
    for ( int y = r->y1; y < r->y2; y++ ) {
        for ( int x = r->x1; x < r->x2; x++ ) {
            tga_set_pixel( tga, x, y, 255 );
        }
    }
}

void watch_draw_time(TGAImage* self, const int hourpos1, const int hourpos2, const int minutepos1, const int minutepos2)
{
    int width = 368;
    int height = 448;
    TGA * tga = tga_new( width, height, 40 );

    Rect r1 = { 0, 0, 368, 15 };
    Rect r2 = { 0, 208, 368, 238 };
    Rect r3 = { 0, 433, 368, 448 };
    Rect r4 = { 0, 0, 15, 448 };
    Rect r5 = { 169, 0, 199, 448 };
    Rect r6 = { 353, 0, 368, 448 };

    draw_rect( tga, &r1 );
    draw_rect( tga, &r2 );
    draw_rect( tga, &r3 );
    draw_rect( tga, &r4 );
    draw_rect( tga, &r5 );
    draw_rect( tga, &r6 );

    Rect p1h0 = { 45, 45, 139, 179 };
    Rect p1h1 = { 15, 15, 139, 209 };
    Rect p1h2 = { 15, 45, 139, 95 };
    Rect p1h22 = { 45, 130, 169, 180 };
    Rect p1h3 = { 15, 45, 139, 95 };
    Rect p1h33 = { 15, 130, 139, 180 };
    Rect p1h4 = { 45, 15, 139, 95 };
    Rect p1h44 = { 15, 130, 139, 209 };
    Rect p1h5 = { 15, 130, 139, 180 };
    Rect p1h55 = { 45, 45, 169, 95 };
    Rect p1h6 = { 45, 130, 139, 180 };
    Rect p1h66 = { 45, 45, 169, 95 };
    Rect p1h7 = { 15, 45, 139, 209 };
    Rect p1h8 = { 45, 45, 139, 95 };
    Rect p1h88 = { 45, 130, 139, 179 };
    Rect p1h9 = { 45, 45, 139, 95 };
    Rect p1h99 = { 15, 130, 139, 180 };
    Rect p2h0 = { 45+184, 45, 139+184, 179 };
    Rect p2h1 = { 15+184, 15, 139+184, 209 };
    Rect p2h2 = { 15+184, 45, 139+184, 95 };
    Rect p2h22 = { 45+184, 130, 169+184, 180 };
    Rect p2h3 = { 15+184, 45, 139+184, 95 };
    Rect p2h33 = { 15+184, 130, 139+184, 180 };
    Rect p2h4 = { 45+184, 15, 139+184, 95 };
    Rect p2h44 = { 15+184, 130, 139+184, 209 };
    Rect p2h5 = { 15+184, 130, 139+184, 180 };
    Rect p2h55 = { 45+184, 45, 169+184, 95 };
    Rect p2h6 = { 45+184, 130, 139+184, 180 };
    Rect p2h66 = { 45+184, 45, 169+184, 95 };
    Rect p2h7 = { 15+184, 45, 139+184, 209 };
    Rect p2h8 = { 45+184, 45, 139+184, 95 };
    Rect p2h88 = { 45+184, 130, 139+184, 179 };
    Rect p2h9 = { 45+184, 45, 139+184, 95 };
    Rect p2h99 = { 15+184, 130, 139+184, 180 };
    
    Rect p1m0 = { 45, 45+223, 139, 179+224 };
    Rect p1m1 = { 15, 15+223, 139, 209+224 };
    Rect p1m2 = { 15, 45+223, 139, 95+224 };
    Rect p1m22 = { 45, 130+223, 169, 180+224 };
    Rect p1m3 = { 15, 45+223, 139, 95+224 };
    Rect p1m33 = { 15, 130+223, 139, 180+224 };
    Rect p1m4 = { 45, 15+223, 139, 95+224 };
    Rect p1m44 = { 15, 130+223, 139, 209+224 };
    Rect p1m5 = { 15, 130+223, 139, 180+224 };
    Rect p1m55 = { 45, 45+223, 169, 95+224 };
    Rect p1m6 = { 45, 130+223, 139, 180+224 };
    Rect p1m66 = { 45, 45+223, 169, 95+224 };
    Rect p1m7 = { 15, 45+223, 139, 209+224 };
    Rect p1m8 = { 45, 45+223, 139, 95+224 };
    Rect p1m88 = { 45, 130+223, 139, 179+224 };
    Rect p1m9 = { 45, 45+223, 139, 95+224 };
    Rect p1m99 = { 15, 130+223, 139, 180+224 };
    Rect p2m0 = { 45+184, 45+223, 139+184, 179+224 };
    Rect p2m1 = { 15+184, 15+223, 139+184, 209+224 };
    Rect p2m2 = { 15+184, 45+223, 139+184, 95+224 };
    Rect p2m22 = { 45+184, 130+223, 169+184, 180+224 };
    Rect p2m3 = { 15+184, 45+223, 139+184, 95+223};
    Rect p2m33 = { 15+184, 130+223, 139+184, 180+224 };
    Rect p2m4 = { 45+184, 15+223, 139+184, 95+223};
    Rect p2m44 = { 15+184, 130+223, 139+184, 209+224 };
    Rect p2m5 = { 15+184, 130+223, 139+184, 180+224 };
    Rect p2m55 = { 45+184, 45+223, 169+184, 95+224 };
    Rect p2m6 = { 45+184, 130+223, 139+184, 180+224 };
    Rect p2m66 = { 45+184, 45+223, 169+184, 95+224 };
    Rect p2m7 = { 15+184, 45+223, 139+184, 209+224 };
    Rect p2m8 = { 45+184, 45+223, 139+184, 95+224 };
    Rect p2m88 = { 45+184, 130+223, 139+184, 179+224 };
    Rect p2m9 = { 45+184, 45+223, 139+184, 95+224 };
    Rect p2m99 = { 15+184, 130+223, 139+184, 180+224 };

        if (hourpos1 == 0)
        {
            draw_rect( tga, &p1h0 );
        }
        if (hourpos1 == 1)
        {
            draw_rect( tga, &p1h1 );
        }
        if (hourpos1 == 2)
        {
            draw_rect( tga, &p1h2 );
            draw_rect( tga, &p1h22 );
        }
        if (hourpos1 == 3)
        {
            draw_rect( tga, &p1h3 );
            draw_rect( tga, &p1h33 );
        }
        if (hourpos1 == 4)
        {
            draw_rect( tga, &p1h4 );
            draw_rect( tga, &p1h44 );
        }
        if (hourpos1 == 5)
        {
            draw_rect( tga, &p1h5 );
            draw_rect( tga, &p1h55 );
        }
        if (hourpos1 == 6)
        {
            draw_rect( tga, &p1h6 );
            draw_rect( tga, &p1h66 );
        }
        if (hourpos1 == 7)
        {
            draw_rect( tga, &p1h7 );
        }
        if (hourpos1 == 8)
        {
            draw_rect( tga, &p1h8 );
            draw_rect( tga, &p1h88 );
        }
        if (hourpos1 == 9)
        {
            draw_rect( tga, &p1h9 );
            draw_rect( tga, &p1h99 );
        }

        if (hourpos2 == 0)
        {
            draw_rect( tga, &p2h0 );
        }
        if (hourpos2 == 1)
        {
            draw_rect( tga, &p2h1 );
        }
        if (hourpos2 == 2)
        {
            draw_rect( tga, &p2h2 );
            draw_rect( tga, &p2h22 );
        }
        if (hourpos2 == 3)
        {
            draw_rect( tga, &p2h3 );
            draw_rect( tga, &p2h33 );
        }
        if (hourpos2 == 4)
        {
            draw_rect( tga, &p2h4 );
            draw_rect( tga, &p2h44 );
        }
        if (hourpos2 == 5)
        {
            draw_rect( tga, &p2h5 );
            draw_rect( tga, &p2h55 );
        }
        if (hourpos2 == 6)
        {
            draw_rect( tga, &p2h6 );
            draw_rect( tga, &p2h66 );
        }
        if (hourpos2 == 7)
        {
            draw_rect( tga, &p2h7 );
        }
        if (hourpos2 == 8)
        {
            draw_rect( tga, &p2h8 );
            draw_rect( tga, &p2h88 );
        }
        if (hourpos2 == 9)
        {
            draw_rect( tga, &p2h9 );
            draw_rect( tga, &p2h99 );
        }

        if (minutepos1 == 0)
        {
            draw_rect( tga, &p1m0 );
        }
        if (minutepos1 == 1)
        {
            draw_rect( tga, &p1m1 );
        }
        if (minutepos1 == 2)
        {
            draw_rect( tga, &p1m2 );
            draw_rect( tga, &p1m22 );
        }
        if (minutepos1 == 3)
        {
            draw_rect( tga, &p1m3 );
            draw_rect( tga, &p1m33 );
        }
        if (minutepos1 == 4)
        {
            draw_rect( tga, &p1m4 );
            draw_rect( tga, &p1m44 );
        }
        if (minutepos1 == 5)
        {
            draw_rect( tga, &p1m5 );
            draw_rect( tga, &p1m55 );
        }
        if (minutepos1 == 6)
        {
            draw_rect( tga, &p1m6 );
            draw_rect( tga, &p1m66 );
        }
        if (minutepos1 == 7)
        {
            draw_rect( tga, &p1m7 );
        }
        if (minutepos1 == 8)
        {
            draw_rect( tga, &p1m8 );
            draw_rect( tga, &p1m88 );
        }
        if (minutepos1 == 9)
        {
            draw_rect( tga, &p1m9 );
            draw_rect( tga, &p1m99 );
        }

        if (minutepos2 == 0)
        {
            draw_rect( tga, &p2m0 );
        }
        if (minutepos2 == 1)
        {
            draw_rect( tga, &p2m1 );
        }
        if (minutepos2 == 2)
        {
            draw_rect( tga, &p2m2 );
            draw_rect( tga, &p2m22 );
        }
        if (minutepos2 == 3)
        {
            draw_rect( tga, &p2m3 );
            draw_rect( tga, &p2m33 );
        }
        if (minutepos2 == 4)
        {
            draw_rect( tga, &p2m4 );
            draw_rect( tga, &p2m44 );
        }
        if (minutepos2 == 5)
        {
            draw_rect( tga, &p2m5 );
            draw_rect( tga, &p2m55 );
        }
        if (minutepos2 == 6)
        {
            draw_rect( tga, &p2m6 );
            draw_rect( tga, &p2m66 );
        }
        if (minutepos2 == 7)
        {
            draw_rect( tga, &p2m7 );
        }
        if (minutepos2 == 8)
        {
            draw_rect( tga, &p2m8 );
            draw_rect( tga, &p2m88 );
        }
        if (minutepos2 == 9)
        {
            draw_rect( tga, &p2m9 );
            draw_rect( tga, &p2m99 );
        }

        tga_write( tga, "aw.tga" );

        tga_free( &tga );
}

int main(int argc, char **argv) {
    int hours = atoi(argv[1]);
    int minutes = atoi(argv[2]);

    if ( hours > 23 || minutes > 59 || hours < 0 || minutes < 0 )
    {
        return 1;
    }

    int hourpos1 = hours < 10 ? 0 : hours/10;
    int hourpos2 = hours < 10 ? hours : hours%10;

    int minutepos1 = minutes < 10 ? 0 : minutes/10;
    int minutepos2 = minutes < 10 ? minutes : minutes%10;

    TGAImage self = {};

    watch_draw_time(&self, hourpos1, hourpos2, minutepos1, minutepos2);

    return 0;
}

