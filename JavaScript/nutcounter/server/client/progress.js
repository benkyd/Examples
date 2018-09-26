//When life gives you CSS, roll your own canvas-based solution
//Written by @UDXS

class ProgressBar {
  //step = percent to change per step
  constructor(context, margin, step) {
    this.canvas = context.canvas;
    this.ctx = context;
    this.margin = margin;
    this.prog = 0;
    this.target = 0;
    this.stepAmt = step;
  }
  get progress() {
    return this.target;
  }
  set progress(target) {
    this.target = target;
    if(target > 1) target = 1;
    if(target < 1) target = 0;
  }
  draw() {
    let radius = Math.min(this.canvas.width,this.canvas.height)/2;
    let start = Math.PI/-2;
    this.ctx.arc(this.canvas.width / 2, this.canvas.height / 2, radius - this.margin, start, 2 * Math.PI * this.prog + start);
  }
  drawBase() {
    let radius = Math.min(this.canvas.width,this.canvas.height)/2;
    this.ctx.arc(this.canvas.width / 2, this.canvas.height / 2, radius - this.margin, 0, 2 * Math.PI);
  }
  step() {
    if (Math.abs(this.target - this.prog) > this.stepAmt)
      this.prog += this.target > this.prog ? this.stepAmt : this.stepAmt * -1;
    else
      this.prog = this.target;
  }
}