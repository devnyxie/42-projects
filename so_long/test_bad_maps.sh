for map in test/maps_err/badextension1.txt test/maps_err/badextension2.ber.txt test/maps_err/badextension3.bber test/maps_err/duplicate_exit.ber test/maps_err/duplicate_player.ber test/maps_err/map1.ber test/maps_err/no_exit.ber test/maps_err/no_object.ber test/maps_err/no_player.ber test/maps_err/no_rectangular.ber test/maps_err/no_rectangular1.ber test/maps_err/no_rectangular2.ber test/maps_err/no_rectangular3.ber test/maps_err/no_rectangular4.ber test/maps_err/no_rectangular5.ber test/maps_err/no_rectangular6.ber test/maps_err/no_rectangular7.ber test/maps_err/no_rectangular8.ber test/maps_err/no_rectangular9.ber test/maps_err/no_valid_road.ber test/maps_err/no_valid_road1.ber test/maps_err/no_valid_road10.ber test/maps_err/no_valid_road11.ber test/maps_err/no_valid_road12.ber test/maps_err/no_valid_road14.ber test/maps_err/no_valid_road15.ber test/maps_err/no_valid_road2.ber test/maps_err/no_valid_road3.ber test/maps_err/no_valid_road4.ber test/maps_err/no_valid_road5.ber test/maps_err/no_valid_road6.ber test/maps_err/no_valid_road7.ber test/maps_err/no_valid_road8.ber test/maps_err/no_valid_road9.ber
do
    valgrind --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
        ./so_long "$map"
done
