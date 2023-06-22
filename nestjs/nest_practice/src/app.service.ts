import { Injectable } from '@nestjs/common';

@Injectable()
export class AppService {
  getHello(hellostring: string): string {
    return hellostring;
  }
}
