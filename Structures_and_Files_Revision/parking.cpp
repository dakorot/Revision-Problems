#include <cstring>
#include <cstdio>

struct ParkingSpot {
    int parking_lot_number;
    char parking_lot_type[12];
    bool occupied;
};

ParkingSpot init_parking_spot(int lot_number, char lot_type[])
{
    ParkingSpot new_spot;
    new_spot.parking_lot_number = lot_number;
    std::strcpy(new_spot.parking_lot_type, lot_type);
    new_spot.occupied = false;

    return new_spot;
}

void occupySpot(ParkingSpot* parking_lot)
{
    parking_lot->occupied = (!(parking_lot->occupied)) ? true : false;
}

void freeSpot(ParkingSpot* parking_lots, int lot_number)
{
    parking_lots[lot_number-1].occupied = false;
}

bool isOccupied(ParkingSpot* parking_lot)
{
    return parking_lot->occupied;
}

void getSpotInfo(ParkingSpot* parking_lot)
{
    printf("%d:\t%s\t - Occupied:\t%B\n", parking_lot->parking_lot_number, parking_lot->parking_lot_type, parking_lot->occupied);
}

int findSpotFor(ParkingSpot* parking_lots, char* lot_type, int size)
{
    for(int i=0; i<size; ++i)
    {
        if(std::strcmp(parking_lots[i].parking_lot_type, lot_type) == 0)
        {
            if(!isOccupied(&parking_lots[i]))
            {
                occupySpot(&parking_lots[i]);
                return parking_lots[i].parking_lot_number;
            }
        }
    }

    return -1;
}

void print_parking_info(ParkingSpot* src, int size)
{
    for(int i=0; i<size; ++i)
        getSpotInfo(&src[i]);
}

int main()

{
    int size = 7, assigned_spot = 0;
    char** types = new char*[4];
    types[0] = "REGULAR";
    types[1] = "HANDICAPPED";
    types[2] = "COMPACT";
    types[3] = "VIP";

    ParkingSpot* spots = new ParkingSpot[size];

    spots[0] = init_parking_spot(1, types[0]);
    spots[1] = init_parking_spot(2, types[1]);
    spots[2] = init_parking_spot(3, types[1]);
    spots[3] = init_parking_spot(4, types[2]);
    spots[4] = init_parking_spot(5, types[2]);
    spots[5] = init_parking_spot(6, types[3]);
    spots[6] = init_parking_spot(7, types[0]);

    assigned_spot = findSpotFor(spots, types[0], size);
    print_parking_info(spots, size);
    printf("==Assigned:\t%d==\n\n", assigned_spot);

    assigned_spot = findSpotFor(spots, types[1], size);
    print_parking_info(spots, size);
    printf("==Assigned:\t%d==\n\n", assigned_spot);

    assigned_spot = findSpotFor(spots, types[1], size);
    print_parking_info(spots, size);
    printf("==Assigned:\t%d==\n\n", assigned_spot);

    assigned_spot = findSpotFor(spots, types[0], size);
    print_parking_info(spots, size);
    printf("==Assigned:\t%d==\n\n", assigned_spot);

    assigned_spot = findSpotFor(spots, types[2], size);
    print_parking_info(spots, size);
    printf("==Assigned:\t%d==\n\n", assigned_spot);

    freeSpot(spots, 2);
    print_parking_info(spots, size);
    printf("\n");
    freeSpot(spots, 4);
    print_parking_info(spots, size);
    printf("\n");
    freeSpot(spots, 7);
    print_parking_info(spots, size);
    printf("\n");

    delete[] types;
    delete[] spots;
    return 0;
}