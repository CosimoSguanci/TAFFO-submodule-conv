; ModuleID = 'a.2.magiclangtmp.ll'
source_filename = "array.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@sum = common dso_local global double 0.000000e+00, align 8, !taffo.info !0
@array = common dso_local global [10 x double] zeroinitializer, align 16, !taffo.initweight !2, !taffo.info !3
@.str = private unnamed_addr constant [23 x i8] c"scalar(range(7, 2000))\00", section "llvm.metadata", !taffo.info !5
@.str.1 = private unnamed_addr constant [8 x i8] c"array.c\00", section "llvm.metadata", !taffo.info !7
@llvm.global.annotations = appending global [1 x { i8*, i8*, i8*, i32 }] [{ i8*, i8*, i8*, i32 } { i8* bitcast ([10 x double]* @array to i8*), i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str, i32 0, i32 0), i8* getelementptr inbounds ([8 x i8], [8 x i8]* @.str.1, i32 0, i32 0), i32 3 }], section "llvm.metadata"

; Function Attrs: noinline nounwind uwtable
define dso_local i32 @main() #0 !taffo.initweight !11 !taffo.funinfo !11 {
entry:
  %0 = load double, double* @sum, align 8, !taffo.info !0
  store double %0, double* getelementptr inbounds ([10 x double], [10 x double]* @array, i64 0, i64 0), align 16, !taffo.initweight !12, !taffo.info !3, !taffo.constinfo !13
  br label %for.cond

for.cond:                                         ; preds = %for.inc, %entry
  %i.0 = phi i32 [ 0, %entry ], [ %inc1, %for.inc ]
  %cmp = icmp slt i32 %i.0, 10
  br i1 %cmp, label %for.body, label %for.end

for.body:                                         ; preds = %for.cond
  %idxprom = sext i32 %i.0 to i64
  %arrayidx = getelementptr inbounds [10 x double], [10 x double]* @array, i64 0, i64 %idxprom, !taffo.initweight !14, !taffo.info !3
  %1 = load double, double* %arrayidx, align 8, !taffo.initweight !12, !taffo.info !3
  %inc = fadd double %1, 1.000000e+00, !taffo.initweight !15, !taffo.info !3, !taffo.constinfo !16
  store double %inc, double* %arrayidx, align 8, !taffo.initweight !12, !taffo.info !3
  br label %for.inc

for.inc:                                          ; preds = %for.body
  %inc1 = add nsw i32 %i.0, 1, !taffo.constinfo !13
  br label %for.cond

for.end:                                          ; preds = %for.cond
  ret i32 0
}

attributes #0 = { noinline nounwind uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!9}
!llvm.ident = !{!10}

!0 = !{i1 false, !1, i1 false, i2 0}
!1 = !{double 0.000000e+00, double 0.000000e+00}
!2 = !{i32 0}
!3 = !{i1 false, !4, i1 false, i2 1}
!4 = !{double 7.000000e+00, double 2.000000e+03}
!5 = !{i1 false, !6, i1 false, i2 0}
!6 = !{double 0.000000e+00, double 1.150000e+02}
!7 = !{i1 false, !8, i1 false, i2 0}
!8 = !{double 0.000000e+00, double 1.210000e+02}
!9 = !{i32 1, !"wchar_size", i32 4}
!10 = !{!"clang version 8.0.1 (tags/RELEASE_801/final)"}
!11 = !{}
!12 = !{i32 2}
!13 = !{i1 false, i1 false}
!14 = !{i32 1}
!15 = !{i32 3}
!16 = !{i1 false, !17}
!17 = !{i1 false, !18, i1 false, i2 0}
!18 = !{double 1.000000e+00, double 1.000000e+00}
