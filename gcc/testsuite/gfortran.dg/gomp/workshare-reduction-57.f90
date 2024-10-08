! { dg-do compile }
! { dg-options "-O2 -fopenmp -fdump-tree-optimized" }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_loop(?:_ull)?_doacross_start \[^\n\r]*, (?:2147483650|-2147483646), 1, " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_loop_end " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_doacross(?:_ull)?_post " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_doacross(?:_ull)?_wait " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_loop(?:_ull)?_dynamic_next " 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_workshare_task_reduction_unregister \\(0\\)" 1 "optimized" } }
! { dg-final { scan-tree-dump-times "__builtin_GOMP_parallel " 1 "optimized" } }

module m
  implicit none (type, external)
  integer(8) :: j
  interface
    subroutine bar(i)
      integer(8) :: i
    end subroutine
  end interface
end module m

subroutine foo(a, b, c)
  use m
  implicit none (type, external)
  integer(8) :: a, b ,c
  integer(8) :: i
  !$omp parallel
  !$omp do ordered(1) reduction (task, *: j) schedule (dynamic)
  do i = a, b, c
    call bar (j)
    !$omp ordered depend(sink: i - 1)
    j = j + 1
    !$omp ordered depend(source)
  end do
  !$omp end parallel
end
