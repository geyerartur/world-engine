module cosmos
    use iso_c_binding, only: c_double
    implicit none

contains

    function cosmos_test() result(value) bind(C, name="world_engine_cosmos_test_impl")
        real(c_double) :: value

        value = 42.0_c_double
    end function cosmos_test

end module cosmos